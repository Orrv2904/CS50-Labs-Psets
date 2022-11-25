# TODO

from cs50 import get_int
import sys

while True:
    Altura = get_int("Altura: ")
    if (Altura >= 1 and Altura <= 8):
        break
for i in range(Altura):
    for j in range(1, Altura - i):
        print(" ", end="")
    for k in range(i + 1):
        print("#", end="")

    print('\n', end="")

# el ciclo i es para la altura, el j para los espacios de bloque y k para imprimir los espacios con su bloque