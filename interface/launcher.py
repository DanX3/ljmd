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
    ("MD steps", c_double),("MD time steps",c_int),("output print freq",c_int)]


inFile=argv[1]
lines=[]
with open(inFile,'r') as inp:
    for el in inp:
        line=el.partition('#')[0]
        lines.append(line)

sys=_mdsys(\
natoms=lines[0],\
mass=lines[1],\
epsilon=lines[2],\
sigma=lines[3],\
rcut=lines[4],\
box_lenght=lines[5],\
restart=lines[6],\
trajectory=lines[7],\
energies=lines[8],\
MD_steps=lines[9],\
MD_time_steps=lines[10],\
output_print_freq=lines[11]\
)



print sys.natoms
