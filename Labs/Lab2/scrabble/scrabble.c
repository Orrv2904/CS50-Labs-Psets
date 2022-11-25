#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
//int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

//Valores ASCII para las letras minúsculas para el alfabeto
int letras_minusculas[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};

// Valores Ascii para las letras mayúsculas para el alfabeto
int letras_mayusculas[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};

int temp_Points [] = {};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    //Si el score1 es mayor que el 2do imprime player 1
    if (score1 > score2)
    {
        printf("Player 1 wins\n");
    }
    //Hace lo mismo que la linea de arriba pero con score2 y player2
    else if (score2 > score1)
    {
        printf("Player 2 wins\n");
    }
    //Lo imprime cuando son iguales
    else
    {
        printf("Tie\n");
    }

}

int compute_score(string word)
{
    // // TODO: Compute and return score for string
    int score = 0;
    //Calcula y devuelve la puntuación de la cadena
    for (int i = 0; i < strlen(word); i++)
    {
        //Comprueba si la letra es superior
        if (isupper(word[i]))
        {
            //Si la letra es mayuscula encuentra el valor en la matriz
            //Si la letra se encuentra toma el punto con el de la matriz y añade el punto total
            for (int j = 0; j < sizeof(letras_mayusculas); j++)
            {
                if (word[i] == letras_mayusculas[j])
                {
                    temp_Points[i] = POINTS[j];
                    score += temp_Points[i];
                }
            }
        }
        else if (islower(word[i]))
        {
            //Hace lo mismo que las lineas de arriba pero con las minisculas
            for (int j = 0; j < sizeof(letras_minusculas); j++)
            {
                if (word[i] == letras_minusculas[j])
                {
                    temp_Points[i] = POINTS[j];
                    score += temp_Points[i];
                }
            }
        }
        //si los caracteres tienen algo mas los ignora
        else
        {
            i += 1;
        }
    }
    //retorna el valor al score
    return score;
}

