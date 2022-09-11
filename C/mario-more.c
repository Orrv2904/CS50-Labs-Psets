#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Ingrese el tamaño de la matriz: ");
    }
    while (n < 1 || n > 8);
    //este for añade la altura
    for (int i = 1; i <= n; i++)
    {
        for (int j = n - i; j >= 1; j--)
        {
            printf(" ");
        }
        //este for añade las columnas de la parte izquierda
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }

        printf("  ");
//-------------------------------------------------------//
//Lorem ipsum
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }

}