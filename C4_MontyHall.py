import random


simulaciones = 100000

ganar_quedandose, ganar_cambiando = 0,0
for simulacion in range(simulaciones):
    premio = random.randint(0,2)
    puerta_inicial = random.randint(0,2)
    if premio == puerta_inicial:
        ganar_quedandose += 1
    else:
        ganar_cambiando += 1

prob_ganar_quedandose = ganar_quedandose/simulaciones
prob_ganar_cambiando = ganar_cambiando/simulaciones
print(f"P(ganar quedandose)={prob_ganar_quedandose}")
print(f"P(ganar cambiandose)={prob_ganar_cambiando}")
