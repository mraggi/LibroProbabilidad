import random

simulaciones = 100000

iguales = 0
distintas = 0
pelotas = ["A","A","A","R","R"]
for simulacion in range(simulaciones):
    x = random.choice(pelotas)
    y = random.choice(pelotas)
    if x == y:
        iguales += 1
    else:
        distintas += 1

probabilidad_iguales = iguales/simulaciones
probabilidad_distintas = distintas/simulaciones
print(f"P(iguales)={probabilidad_iguales}")
print(f"P(distintas)={probabilidad_distintas}")
