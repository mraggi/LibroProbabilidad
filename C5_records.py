import random

def num_records_rotos(saltos):
    total, mejor = 0, -1
    for salto in saltos:
        if salto > mejor:
            total += 1
            mejor = salto
    return total

n = 10
simulaciones = 100000
saltos = list(range(n))

total_records = 0
for simulacion in range(simulaciones):
    random.shuffle(saltos)
    total_records += num_records_rotos(saltos)

prom_records = total_records/simulaciones
print(f"E(num records rotos)={prom_records}")
