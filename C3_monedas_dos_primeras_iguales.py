import random

simulaciones = 100000

ocurrencias = 0
for simulacion in range(simulaciones):
    x,y,z = [random.randint(0,1) for i in range(3)]
    if x == y:
        ocurrencias += 1

probabilidad = ocurrencias/simulaciones
print(f"P(dos primeras iguales)={probabilidad}")
