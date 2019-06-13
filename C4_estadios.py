import random

def gano_Ana(estadio):
    p = 0.4 # estadio == "C"
    if estadio == "A":
        p = 0.6
    elif estadio == "B":
        p = 0.5
    return random.random() < p

simulaciones = 100000

partidos_ganados = 0
for simulacion in range(simulaciones):
    estadio = random.choice(["A","A","A","B","B","C"])
    if gano_Ana(estadio):
        partidos_ganados += 1

probabilidad = partidos_ganados/simulaciones
print(f"P(ganar)={probabilidad}")
