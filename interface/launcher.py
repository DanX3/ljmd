from ctypes import *
from numpy import *
from sys import *
"""
data = CDLL('./lib/data.so')
force = CDLL('./lib/force.so')
vel = CDLL('./lib/ververlet.so')
helpers = CDLL('./lib/helpers.so')
output = CDLL('./lib/output.so')
input_ = CDLL('./lib/input_.so')


"""
class _mdsys(Structure):
    [("natoms",c_int),("mass",c_double),("epsilon", c_double),\
    ("sigma",c_double),("rcut",c_double),("box_lenght",c_double),\
    ("restart",c_char_p),("trajectory",c_char_p),("energies",c_char_p),\
    ("MD_steps", c_double),("MD_time_steps",c_int),("output_print_freq",c_int),\
    ("ekin",c_double),("epot",c_double),("temp",c_double),\
    ("rx", c_double),("ry",c_double),("rz",c_double),\
    ("vx", c_double),("vy",c_double),("vz",c_double),\
    ("fx", c_double),("fy",c_double),("fz",c_double)]



inFile=argv[1]
lines=[]
with open(inFile,'r') as inp:
    for el in inp:
        line=el.partition('#')[0]
        lines.append(line)

sys=_mdsys(\
natoms=(int)(lines[0]),\
mass=(float)(lines[1]),\
epsilon=(float)(lines[2]),\
sigma=(float)(lines[3]),\
rcut=(float)(lines[4]),\
box_lenght=(float)(lines[5]),\
restart=lines[6],\
trajectory=lines[7],\
energies=lines[8],\
MD_steps=(int)(lines[9]),\
MD_time_steps=(float)(lines[10]),\
output_print_freq=(int)(lines[11])\
)




print type(sys.natoms)


#sys=_mdsys(inp[0,0])
