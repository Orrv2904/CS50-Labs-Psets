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
    //Este for imprime la altura
    for (int i = 1; i <= n; i++)
    {
        //este for imprime las filas
        for (int j = n - i; j >= 1; j--)
        {
            printf(" ");
        }
        //este for imprime las columnas con su espacio
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");

    }
    return 0;
}