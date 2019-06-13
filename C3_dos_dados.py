import random

simulaciones = 100000

ocurrencias = 0
for simulacion in range(simulaciones):
    x,y = [random.randint(1,6) for i in range(2)]
    if x+y == 8:
        ocurrencias += 1

probabilidad = ocurrencias/simulaciones
print(f"P(dos primeras iguales)={probabilidad}")
