import numpy as np
import matplotlib.pyplot as plt

for j in range(1,5):
    f =  open("num_result_pow%i.txt" %(j), 'r')
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

    plt.plot(x, v, label='n = %i' %(10**j))




def u(x):
    return 1-(1-np.exp(-10))*x-np.exp(-10*x)

x2 = np.linspace(0.00005,0.9995,1e4)
plt.plot(x2, u(x2) ,label="Analytical solution")
plt.legend()
plt.title('Solution of set of linear equations')
plt.xlabel('x')
plt.ylabel('y')
plt.savefig('1b_plot', dpi=400)
plt.show()
