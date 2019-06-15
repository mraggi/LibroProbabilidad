import random

def enteros_aleatorios_de_suma(suma, n):
    U = list(range(suma+n-1))
    L = random.sample(U,n-1)
    L.append(-1)
    L.append(suma+n-1)
    L.sort()
    return [L[i+1]-L[i]-1 for i in range(n)]

print(enteros_aleatorios_de_suma(5,3))
