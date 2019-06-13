import random

def bernoulli(p):
    return True if random.random() < p else False

simulaciones = 100000

n = 9
p = 0.4
resultados = [0]*(n+1)

for simulacion in range(simulaciones):
    b = sum([bernoulli(p) for i in range(n)])
    resultados[b] += 1

for i,r in enumerate(resultados):
    print(f"{i}: " + '*'*int(100*r/simulaciones))
