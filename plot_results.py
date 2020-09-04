import numpy as np
import matplotlib.pyplot as plt

f =  open("num_result_pow2.txt", 'r')
f.readline()
lines = f.readlines()
x = np.zeros(len(lines))
v = np.zeros(len(lines))
i = 0
for line in lines:
    split = line.split()
    x[i] = split[0]
    v[i] = split[1]
    i += 1

x2 = np.linspace(0.0005,0.995,1e4)
def u(x):
    return 1-(1-np.exp(-10))*x-np.exp(-10*x)

plt.plot(x, v)
plt.plot(x2, u(x2) ,label="Analytical solution")
plt.legend()
plt.show()
