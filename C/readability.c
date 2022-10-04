#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    string text = get_string("Text: ");

    int letras = 0;


    for (int j = 0; j < strlen(text); j++) //se recorre la cadena y strlen te da el tamaño de la cadena
    {
        if (isalpha(text[j]))//Verifica si el caracter esta dentro del alfabeto, sea minuscula o mayuscula
        {
            letras++; //aumenta las letras
        }
    }


    /******************************************************************************/
    //Hace lo mismo de arriba peero con palabras
    int palabras = 1;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')//verifica si exite una palabra, reconociendo el espacio entre palabra
        {
            palabras++;
        }
    }

    /******************************************************************************/

    int oraciones = 0; //Lo mismo que arriba pero con oraciones

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') //verifica si existe una oracion, cada oracion termina
            //en . || ! || ? | asi verifica que si termina en un caracter asi, es una oracion
        {
            oraciones++;
        }
    }


    /*****************************************************************************/

    //calcular el grado
    //siguiendo la formula de Coleman-Liau

    float L = ((float)(letras) / (float)(palabras)) * 100; //Número de letras por cada 100 palabras
    float S = ((float)(oraciones) / (float)(palabras)) * 100; //Número de oraciones por cada 100 palabras

    float index  = 0.0588 * L - 0.296 * S - 15.8;

    int index2 = round(index); //Convierte el index flotante que almacena la formula, a un index entero
    if (index2 >= 16) //verifica que el index entero sea mayor que 16
    {
        printf("Grade 16+\n");
    }
    else if (index2 < 1) //igual que el de arriba
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index2);
    }
}
