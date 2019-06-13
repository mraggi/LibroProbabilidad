import random

def primera_aguila():
    for i in range(1,999):
        tiro = random.randint(0,1)
        if tiro == 1:
            return i

simulaciones = 100000

menos_de_4,par,impar = 0,0,0
for simulacion in range(simulaciones):
    num_tiros = primera_aguila()
    if num_tiros < 4:
        menos_de_4 += 1
    if num_tiros%2 == 0:
        par += 1
    else:
        impar += 1

prob_menos_de_4 = menos_de_4/simulaciones
prob_par = par/simulaciones
prob_impar = impar/simulaciones
print(f"P(menos de 4)={prob_menos_de_4}")
print(f"P(par)={prob_par}")
print(f"P(impar)={prob_impar}")
