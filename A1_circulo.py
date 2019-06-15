import random

def dentro_de_circulo(x,y):
    return x*x+y*y <= 1.

def aleatorio_en_circulo():
    (x,y) = (random.random(), random.random())
    while not dentro_de_circulo(x,y):
        (x,y) = (random.random(), random.random())
    return (x,y)

print(aleatorio_en_circulo())
