#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //if argumento c  no sea igual a 2 imprima error
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        //si hay 2 argumentos comprueba si tiene digitos
        string k = argv[1];
        for (int i = 0; i < strlen(k); i++)
        {
            if (isdigit(k[i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        //Convierto el argumento 2 a entero
        int miKey = atoi(k);

        string plaintext = get_string("Plaintext: ");

        for (int i = 0; i < strlen(plaintext); i++)
        {
            if (isupper(plaintext[i]))
            {
                //aqui necesite cambiar la A a 0 para convertirlo al 65 en ASCII
                plaintext[i] = (plaintext[i] - 65);
                plaintext[i] = (plaintext[i] + miKey) % 26;
                plaintext[i] = (plaintext[i] + 65);
            }
            if (islower(plaintext [i]))
            {
                plaintext[i] = (plaintext[i] - 97);
                plaintext[i] = (plaintext[i] + miKey) % 26;
                plaintext[i] = (plaintext[i] + 97);
            }
            //de este if no estoy muy seguro, siento que repito lo mismo que arriba
            //por si acaso
            // if isalpha(plaintext[i] == 0)
            // {
            //     plaintext[i] = plaintext[i];
            // }
            printf("Ciphertext: %s", plaintext);
            printf("\n");
        }
    }
}