import random

def aleatorios_de_suma_1(n):
    L = [random.random() for i in range(n-1)]
    L.append(0)
    L.append(1)
    L.sort()
    return [L[i+1]-L[i] for i in range(n)]

print(aleatorios_de_suma_1(3))
