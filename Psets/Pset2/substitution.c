#include <stdio.h>
#include <cs50.h>
#include <string.h> //strlen()
#include <ctype.h> // operacion para upper, lower

int checkKey(); //Para el valor de la clave
void Do_substitute(); //Para las sustituciones
void alpha_arr_val(char pos, string key);
//para obtener el valor de cada elemento de texto (ejp:plaintext = h|array alfabético = 8 {a=0, b=1 .....z=26})

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (strlen(argv[1]) == 26)
        {
            for (int i = 0; i < strlen(argv[1]) ; i++) //comprueba el elemento en la ejecucion de la terminal
            {

                if (! isalpha(argv[1][i])) //si no contiene alfab
                {
                    printf("Key must contain 26 characters.\n");
                    return 1;
                }

                for (int j = i + 1 ; j < strlen(argv[1]) ; j++) //comprueba el elemento siguiente de arg[i]
                {

                    if (toupper(argv[1][j]) == toupper(argv[1][i])) //solo comprueba lo que se repite
                    {
                        printf("Key must not contain repeated alphabets.\n");
                        return 1;
                    }
                }
            }

            Do_substitute(argv[1]);

        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    return 0;
}


void Do_substitute(string key)
{
    string p = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(p); i++)
    {
        if (isalpha(p[i])) //comprueba que el elemento de p sea alfabeto
        {
            char x = p[i];
            if (islower(p[i]))
            {
                alpha_arr_val(tolower(x), key); //pasando p[i] en minúsculas
            }
            else
            {
                alpha_arr_val(toupper(x), key); //lo mismo pero en mayúsculas
            }


        }
        else
        {
            printf("%c", p[i]);
        }
    }

    printf("\n");

}
void alpha_arr_val(char pos, string key) //aqui pasa el elemto [i] de p upper/lower
{
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //matriz de alfabeto

    for (int i = 0; i < strlen(alpha); i++) //accede al elemento de la matriz
    {
        if (islower(pos)) // p[i] es lower
        {
            if (pos == tolower(alpha[i]))
            {
                printf("%c", tolower(key[i]));
            }
        }
        else //lo mismo pero si es upper
        {
            if (pos == toupper(alpha[i]))
            {
                printf("%c", toupper(key[i]));
            }
        }
    }
}