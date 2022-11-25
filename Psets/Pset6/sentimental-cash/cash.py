# TODO

from cs50 import get_float
import sys

while True:
    dolares = get_float("Change owed: ")
    if(dolares > 0):
        break

centavos = round(dolares * 100)
contador = 0

while centavos >= 25:
    centavos = centavos - 25
    contador += 1
while centavos >= 10:
    centavos = centavos - 10
    contador += 1
while centavos >= 5:
    centavos = centavos - 5
    contador += 1
while centavos >= 1:
    centavos = centavos - 1
    contador += 1
print(contador)
# 
#