import sys

sys.setrecursionlimit(2 ** 20)
value = []
weight = []
C = {}


def compute_C(i, x):
    key = str(i) + ',' + str(x)
    if(i == 0):
        return 0
    if(key in C):
        return C[key]
    else:
        if(x < weight[i - 1]):
            C[key] = compute_C(i - 1, x)
            return C[key]
        else:
            C[key] = max(
                [compute_C(i - 1, x),
                 compute_C(i - 1, x - weight[i - 1]) + value[i - 1]])
            return C[key]
            

f = open('data2.txt')
lines = f.readlines()
x = lines[0].replace('\n', '').split(' ')
size = int(x[0])
N = int(x[1])
for i in range(1, N + 1):
    x = lines[i].replace('\n', '').split(' ')
    value.append(int(x[0]))
    weight.append(int(x[1]))
print(compute_C(N, size))
