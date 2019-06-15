import random

def encontrar_esposo(novios, a):
    if a == 0: return novios[0]
    The_One_That_Got_Away = max(novios[0:a])
    for novio in novios[a:]:
        if (novio > The_One_That_Got_Away):
            return novio
    return novios[-1]

simulaciones = 100000

n = 15
novios = list(range(n))

# Regresa probabilidad de encontrar soulmate, promedio
def simular(a):
    soulmate = 0
    total = 0
    for simulacion in range(simulaciones):
        random.shuffle(novios)
        esposo = encontrar_esposo(novios,a)
        if esposo == n-1:
            soulmate += 1
        total += esposo
    return soulmate/simulaciones, total/simulaciones

for a in range(n):
    prob, prom = simular(a)
    print(f"Para a={a}, probabilidad={prob}, promedio={prom+1}")
