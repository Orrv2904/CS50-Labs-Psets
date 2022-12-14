#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //Verificar uso
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    //Abrir documento
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        return 1;
    }

    FILE *img = NULL;

    BYTE buffer[512];
    char filename[8];
    int counter = 0;
    while (fread(buffer, sizeof(BYTE), 512, file) == 512)
    {
        //comprueba si el inicio de img
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //luego comienza a escribir una nueva imagen
            if (counter == 0)
            {
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(&buffer, sizeof(BYTE), 512, img);
                counter += 1;
            }
            //Si el inicio de la imagen no es la primera, cierra el archivo y escribe uno nuevo
            else if (counter > 0)
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(&buffer, sizeof(BYTE), 512, img);
                counter += 1;
            }
        }
        //si no es el inicio de la nueva img, sigue escribiendola
        else if (counter > 0)
        {
            fwrite(&buffer, sizeof(BYTE), 512, img);
        }

    }

    fclose(file);
    fclose(img);
}