import random

simulaciones = 100000

n = 10
a = list(range(n))

S,T,SyT = 0,0,0
for simulacion in range(simulaciones):
    random.shuffle(a)
    if a[0] > a[1]:
        S += 1
    if a[1] > a[2]:
        T += 1
    if a[0] > a[1] and a[1] > a[2]:
        SyT += 1

prob_S = S/simulaciones
prob_T = T/simulaciones
prob_SyT = SyT/simulaciones
print(f"P(S)={prob_S}")
print(f"P(T)={prob_T}")
print(f"P(S|T)={prob_SyT/prob_T}")
