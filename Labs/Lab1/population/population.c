#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int n, n2;
    int years = 0;
    do
    {
        //printf("Ingrese el tamaño inicial de la población: ");
        //scanf("%d", &n);
        n = get_int("Enter the initial population size: ");
        if(n < 9)
        {
          printf("if we start with less than 9 llamas, the llamas population will quickly die off!\n");
        }
    }
    while(n<9);
// TODO: Prompt for end size

    do
    {
    //printf("Ingrese el tamaño final de la población: ");
    //scanf("%d", &n2);
     n2 = get_int("Enter the final population size: ");
     if(n2 < n)
     {
        printf("Choose larger than the initial size\n");
     }
    }
    while(n2 < n);

// TODO: Calculate number of years until we reach threshold

    while(n < n2)
    {
     n = n+(n / 3) - (n / 4);
     years++;
    }
    // TODO: Print number of years

    printf("Years: %d\n", years);
}