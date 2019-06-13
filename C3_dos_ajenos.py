import random

def se_intersectan(A,B):
    B = set(B)
    for a in A:
        if a in B:
            return True
    return False

simulaciones = 100000

X = list(range(10))
ocurrencias = 0
for simulacion in range(simulaciones):
    A = random.sample(X,4)
    B = random.sample(X,4)
    if se_intersectan(A,B):
        ocurrencias += 1

probabilidad = ocurrencias/simulaciones
print(f"P(se intersectan)={probabilidad}")
