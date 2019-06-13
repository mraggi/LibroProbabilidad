import random

simulaciones = 100000

def tirar():
    if random.random() < 0.8:
        return "Izquierda"
    else:
        return "Derecha"

def es_gol(tiro):
    p = 0.7 if tiro == "Izquierda" else 0.6
    return random.random() < p

goles = 0
for simulacion in range(simulaciones):
    tiro = tirar()
    if es_gol(tiro):
        goles += 1

probabilidad = goles/simulaciones
print(f"P(gol)={probabilidad}")
