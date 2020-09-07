import numpy as np

n6 = []
n7 = []

with open("times_regular.txt", 'r') as f:
    lines = f.readlines()

    for line in lines:
        split = line.split()
        if split[0] == "1000000":
            n6.append(float(split[1]))
        elif split[0] == "10000000":
            n7.append(float(split[1]))
        else:
            pass

n6 = np.asarray(n6)
n7 = np.asarray(n7)

n6s = []
n7s = []

with open("times_spec.txt", 'r') as f:
    lines = f.readlines()

    for line in lines:
        split = line.split()
        if split[0] == "1000000":
            n6s.append(float(split[1]))
        elif split[0] == "10000000":
            n7s.append(float(split[1]))
        else:
            pass

n6s = np.asarray(n6s)
n7s = np.asarray(n7s)


print(np.mean(n6), np.mean(n7))

print(np.mean(n6s), np.mean(n7s))
