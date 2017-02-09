#from ctype import *
from numpy import *
"""
data = CDLL(./lib/data.so)
force = CDLL(./lib/force.so)
vel = CDLL(./lib/ververlet.so)
helpers = CDLL(./lib/helpers.so)
output = CDLL(./lib/output.so)
input_ = CDLL(./lib/input_.so)



class _mdsys(structure):
    [("natoms",c_int),("mass",c_double),("epsilon", c_double),\
    ("sigma",c_double),("rcut",c_double),("box_lenght",c_double)\
    ("restart",c_char_p),("trajectory",c_char_p),("energies",c_char_p)\
    ("MD steps", c_double),("MD time steps",c_int),("output print freq",c_int)]
"""
inp=set(open('../examples/argon_108.inp'))
print inp
#sys=_mdsys(inp[0,0])
