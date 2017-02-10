from ctypes import *
#from numpy import *
from sys import *
import os

cwd=os.getcwd()
lib_d=cwd+'/lib'


clibs=CDLL(''+lib_d+'/libljmd.so')

#("restart",c_char_p),("trajectory",c_char_p),("energies",c_char_p),\

class mdsys_t (Structure):
    _fields_ =[("natoms",c_int),("nfi",c_int),("nsteps",c_int),\
    ("dt", c_double),("mass",c_double),("epsilon", c_double),\
    ("sigma",c_double),("box",c_double),("rcut",c_double),\
    ("ekin",c_double),("epot",c_double),("temp",c_double),\
    ("rx", POINTER(c_double)),("ry",POINTER(c_double)),("rz",POINTER(c_double)),\
    ("vx", POINTER(c_double)),("vy",POINTER(c_double)),("vz",POINTER(c_double)),\
    ("fx", POINTER(c_double)),("fy",POINTER(c_double)),("fz",POINTER(c_double))]



inFile=argv[1]
lines=[]
with open(inFile,'r') as inp:
    for el in inp:
        line=el.partition('#')[0]
        lines.append(line)
sys=mdsys_t (\
natoms=(int)(lines[0]),\
nfi=(int)(0),\
nsteps=(int)(lines[9]),\
dt=(float)(lines[10]),\
mass=(float)(lines[1]),\
epsilon=(float)(lines[2]),\
sigma=(float)(lines[3]),\
rcut=(float)(lines[4]),\
box=(float)(lines[5]),\
ekin=(float)(0),\
epot=(float)(0),\
temp=(float)(0)
)
nprints=(int)(lines[11])
"""
restart=(str)(lines[6].partition(' ')[0]),\
trajectory=lines[7],\
energies=lines[8],\
"""
sys.rx=(c_double * sys.natoms)()
sys.ry=(c_double * sys.natoms)()
sys.rz=(c_double * sys.natoms)()
sys.vx=(c_double * sys.natoms)()
sys.vy=(c_double * sys.natoms)()
sys.vz=(c_double * sys.natoms)()
sys.fx=(c_double * sys.natoms)()
sys.fy=(c_double * sys.natoms)()
sys.fz=(c_double * sys.natoms)()


# Read restart
rest=open(cwd+'/'+(lines[6].partition(' ')[0]),"r")
if (rest):
    i=0
    j=0
    for line in rest:
        if (i<sys.natoms):

            data=line.split()
            sys.rx[i]=(float)(data[0])
            sys.ry[i]=(float)(data[1])
            sys.rz[i]=(float)(data[2])
            i+=1
        else:
            data=line.split()
            sys.vx[j]=(float)(data[0])
            sys.vy[j]=(float)(data[1])
            sys.vz[j]=(float)(data[2])
            j+=1
    rest.close()
    clibs.azzero(sys.fx, sys.natoms)
    clibs.azzero(sys.fy, sys.natoms)
    clibs.azzero(sys.fz, sys.natoms)


else:
    print "cannot read restart file"


# initialize forces and energies
sys.nfi=0
#print "before force call: sys.rx[0]=  %f" % sys.rx[0]

clibs.force(byref(sys))
clibs.ekin(byref(sys))
#print "after force call: sys.rx[0]=  %f" % sys.rx[0]

class File(Structure):
    pass
convert_file = pythonapi.PyFile_AsFile
convert_file.restype = POINTER(File)
convert_file.argtypes = [py_object]


erg=open(lines[8],"w")
traj=open(lines[7],"w")

print "***** Starting simulation with %d atoms for %d steps ******" % (sys.natoms, sys.nsteps)
print "     NFI              TEMP                EKIN                  EPOT                  ETOT\n"
clibs.output(byref(sys),convert_file(erg),convert_file(traj))

# main MD loop

for i in xrange(1,sys.nsteps+1):
    #write output if requested
    sys.nfi=i
    if ((sys.nfi % nprints) == 0):
        clibs.output(byref(sys),convert_file(erg),convert_file(traj))
    #propagate system and recompute energies

    clibs.velverlet(byref(sys))
    clibs.ekin(byref(sys))
print "************ SIMULATION DONE ************"

erg.close()
traj.close()
