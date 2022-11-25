#include "helpers.h"
#include <math.h>

#define RED_DOLOR 0
#define GREEN_COLOR 1
#define BLUE_COLOR 2

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //    Azulito = image[i][j].rgbtBlue;
            //    Verdecito = image[i][j].rgbtGreen;
            //    Rojito = image[i][j].rgbtRed;

            //    Color float = round((Azulito + Verdecito + Rojito) / 3);
            //    image[i][j].rgbtBlue = Color;

            int valor = round(((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0));
            image[i][j].rgbtRed = valor;
            image[i][j].rgbtGreen = valor;
            image[i][j].rgbtBlue = valor;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++) //este for es para calcular la formula de sepia para el rgb
        {
            //Formula para convertir los valores de la imagen por cada tipo de rgb para un rgb tipo Sepia
            int sepiaRed = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            int sepiaGreen = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            int sepiaBlue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));

            //Si el valor es mas alto que 255, se establece que 255 es el maximo para evitar mayor dimension de la imagen

            if (sepiaRed >= 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen >= 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue >= 255)
            {
                sepiaBlue = 255;
            }
            //Aca es para darle los valores que se obtengan de la formula de Sepia a los de rgb y que ponga los valores pero en tono tipo rgb
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    //Cualquier píxel del lado izquierdo de la imagen debería acabar en el derecho, y viceversa
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1]; //para ajustar que la imagen del ancho se reste y se sobreponga a la otra posicion
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Crea una imagen temporal para el desenfoque
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //el valor total de la imagen
            int total_Red, total_Blue, total_Green;
            total_Red = total_Blue = total_Green = 0;
            float counter = 0.00;

            //agarra los pixeles que esten cerca con las posiciones x && y
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int valorX = i + x;
                    int valorY = j + y;

                    //verifica si el pixel que este cerca existe en la altura y anchura
                    if (valorX < 0 || valorX > (height - 1) || valorY < 0 || valorY > (width - 1))
                    {
                        continue;
                    }

                    //capruta el valor de la imagen
                    total_Red += image[valorX][valorY].rgbtRed;
                    total_Green += image[valorX][valorY].rgbtGreen;
                    total_Blue += image[valorX][valorY].rgbtBlue;

                    counter++;
                }

                //calcula la media de los pixeles vecinos del cuadro
                temp[i][j].rgbtRed = round(total_Red / counter);
                temp[i][j].rgbtGreen = round(total_Green / counter);
                temp[i][j].rgbtBlue = round(total_Blue / counter);
            }
        }

    }

    //pasa la imagen que tiene el blur a la imagen original
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }

    return;
}
