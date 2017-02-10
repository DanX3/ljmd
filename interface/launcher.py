from ctypes import *
from numpy import *
from sys import *
import os

cwd=os.getcwd()
lib_d=cwd+'/lib'
print lib_d

clibs=CDLL(''+lib_d+'/all_in.so')

"""
data = CDLL(''+lib_d+'/datafile.so')
helpers = CDLL(''+lib_d+'/helpers.so')
force = CDLL(''+lib_d+'/force.so')
velverlet = CDLL(''+lib_d+'/velverlet.so')

output = CDLL(''+lib_d+'/output.so')
input_ = CDLL(''+lib_d+'/input.so')
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

with open(inFile,'r') as inp:
    for el in inp:
        line=el.partition('#')[0]
        lines.append(line)


print type(sys.natoms)


#sys=_mdsys(inp[0,0])
