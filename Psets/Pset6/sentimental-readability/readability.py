# TODO

from cs50 import get_string
import sys
# tecto obtiene valor string
texto = get_string("Text: ")
n = len(texto)
letras = 0
palabras = 1
oraciones = 0

# Contador
for i in range(n):
    if texto[i].isalpha():
        letras += 1
    if texto[i] == ' ':
        palabras += 1
    if texto[i] == '.' or texto[i] == '?' or texto[i] == '!':
        oraciones += 1
    else:
        i += 1

# print(f"{letras} letras(s)")

L = letras / palabras * 100
S = oraciones / palabras * 100

flotl = float(L)
flots = float(S)

index = 0.0588 * flotl - 0.296 * flots - 15.8

grado = round(index)

if grado >= 16:
    print("Grade 16+")
elif grado < 1:
    print("Before Grade 1")
else:
    print(f"Grade {grado}")

# Operaciones para el grado de las letras, oraciones y palabras