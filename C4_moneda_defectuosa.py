import random

def tiro(moneda):
    if moneda == "normal":
        return "aguila" if random.randint(0,1) else "sol"
    else:
        return "aguila"

simulaciones = 100000

aguilas = 0
defectuosos = 0
for simulacion in range(simulaciones):
    moneda = random.choice(["normal", "defectuosa"])
    if tiro(moneda) == "aguila":
        aguilas += 1
        if moneda == "defectuosa":
            defectuosos += 1

probabilidad = defectuosos/aguilas
print(f"P(defectuosa)={probabilidad}")
