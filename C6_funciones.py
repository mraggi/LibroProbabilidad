import random
import math

def E(X):
    return sum(X)/len(X)

def Var(X):
    X2 = [x**2 for x in X]
    EX = E(X)
    return E(X2) - EX**2

def sigma(X):
    return math.sqrt(Var(X))

def cov(X,Y):
    XY = [x*y for x,y in zip(X,Y)]
    return E(XY) - E(X)*E(Y)

def corr(X,Y):
    return cov(X,Y)/(sigma(X)*sigma(Y))
