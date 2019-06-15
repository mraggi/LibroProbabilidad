import random

def enteros_aleatorios_de_suma(suma, n):
    U = list(range(suma+n-1))
    L = random.sample(U,n-1)
    L.append(-1)
    L.append(suma+n-1)
    L.sort()
    return [L[i+1]-L[i]-1 for i in range(n)]

D = dict()
for i in range(1000000):
    U = tuple(enteros_aleatorios_de_suma(1,3))
    if U in D.keys():
        D[U] += 1
    else:
        D[U] = 1

for key,value in D.items():
    print(f"{key}: {value}")
