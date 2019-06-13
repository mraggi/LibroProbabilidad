import random

simulaciones = 100000

n = 59

repetidos = 0

for simulacion in range(simulaciones):
    dias = set()
    for i in range(n):
        cumple = random.randint(1,365)
        if cumple in dias:
            repetidos += 1
            break
        else:
            dias.add(cumple)

probabilidad = repetidos/simulaciones
print(f"P(repetir)={probabilidad}")
