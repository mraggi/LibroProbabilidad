import random

simulaciones = 100000

ocurrencias = 0
condicion_satisfecha = 0
for simulacion in range(simulaciones):
    tiros = [random.randint(0,1) for i in range(5)]
    if tiros.count(1) == 3:
        condicion_satisfecha += 1
        if tiros[0] == 1:
            ocurrencias += 1

probabilidad = ocurrencias/condicion_satisfecha
print(f"P(primera sol)={probabilidad}")
