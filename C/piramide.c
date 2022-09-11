#include <stdio.h>
#include <cs50.h>
int main()
{
   //int n = get_int("Ingrese el tamaño de la matriz: ");
   int n;
    do
    {
        n = get_int("Ingrese el tamaño de la matriz: ");
    }
    while(n<1);
    for(int i = 0; i<n; i++)
    {
    for(int o = 0; o<n;o++)
        {
	        printf("#");
        }

        printf("\n");
    }
    return 0;
}