import numpy as np
import matplotlib.pyplot as plt

with open("test_d.txt",'r') as f:
    lines = f.readlines()
    x = np.zeros(len(lines))
    d = np.zeros(len(lines))

    i = 0
    for line in lines:
        split = line.split()

        x[i] = split[0]
        d[i] = split[1]
        i += 1
    plt.plot(x,d,label='d')

n = 100
h = 1/(n+1)
x = np.linspace(0,1,n+2)

b = h**2*100*np.exp(-10*x)
print(b)
plt.plot(x,b,label='anal')
plt.legend()
plt.show()
