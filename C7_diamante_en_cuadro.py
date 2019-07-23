import random

def punto_en_cuadro():
    return (random.random(), random.random())

def esta_en_diamante(x,y):
    return x+y < 1 and x-y < 1 and -x+y < 1 and -x-y < 1

simulaciones = 100000

dentro = 0
for simulacion in range(simulaciones):
    (x,y) = punto_en_cuadro()
    if esta_en_diamante(x,y):
        dentro += 1

probabilidad = dentro/simulaciones
print(f"P(caer dentro)={probabilidad}")
