from numba import jit
import numpy as np
import math
import time

# This is the function decorator syntax and is equivalent to `hypot = jit(hypot)`.
# The Numba compiler is just a function you can call whenever you want!
@jit
def hypot(x, y):
    # Implementation from https://en.wikipedia.org/wiki/Hypot
    x = abs(x);
    y = abs(y);
    t = min(x, y);
    x = max(x, y);
    t = t / x;
    return x * math.sqrt(1+t*t)

c = np.arange(16).reshape((2, 8))
# print('c:', c)

import numpy as np

def add(x, y):
    return x + y

# Vectorize the add function
vectorized_add = np.vectorize(add)

# Create two numpy arrays
arr1 = np.array([1, 2, 3, 4])
arr2 = np.array([10, 20, 30, 40])

# Apply the vectorized function
result = add(arr1, arr2)
print(result)