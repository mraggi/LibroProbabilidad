import random
from C6_funciones import cov, corr

simulaciones = 100000

X, Y = [], []
for simulacion in range(simulaciones):
    A,B,C = [random.randint(1,6) for i in range(3)]
    x = A+B
    y = B+C
    X.append(x)
    Y.append(y)

print(f"cov(X,Y)={cov(X,Y)}")
print(f"corr(X,Y)={corr(X,Y)}")
