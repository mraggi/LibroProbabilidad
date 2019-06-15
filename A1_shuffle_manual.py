import random

def manual_shuffle(L):
    n = len(L)
    for i in range(n-1):
        j = random.randint(i,n-1)
        L[i], L[j] = L[j], L[i] # swap
