import random

def num_fijos(regalos):
    total = 0
    for i,r in enumerate(regalos):
        if i == r:
            total += 1
    return total

n = 8
simulaciones = 100000
regalos = list(range(n))


total_puntos_fijos = 0
for simulacion in range(simulaciones):
    random.shuffle(regalos)
    total_puntos_fijos += num_fijos(regalos)

prom_puntos_fijos = total_puntos_fijos/simulaciones
print(f"E(num puntos fijos)={prom_puntos_fijos}")
