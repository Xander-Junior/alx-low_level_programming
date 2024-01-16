import random
import ctypes

# Load the shared library
cops = ctypes.CDLL('./100-operations.so')

# Define the return types of the C functions (assuming they return int)
cops.add.restype = ctypes.c_int
cops.sub.restype = ctypes.c_int
cops.mul.restype = ctypes.c_int
cops.div.restype = ctypes.c_int
cops.mod.restype = ctypes.c_int

# Generate random numbers
a = random.randint(-111, 111)
b = random.randint(-111, 111)

# Call the C functions and print the results
print(f"{a} + {b} = {cops.add(a, b)}")
print(f"{a} - {b} = {cops.sub(a, b)}")
print(f"{a} x {b} = {cops.mul(a, b)}")
print(f"{a} / {b} = {cops.div(a, b)}")
print(f"{a} % {b} = {cops.mod(a, b)}")
