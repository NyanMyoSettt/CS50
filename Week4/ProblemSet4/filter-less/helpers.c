#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int averageValue;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            averageValue = ((image[i][j].rgbtBlue) + (image[i][j].rgbtGreen) + (image[i][j].rgbtRed)) / 3;
            image[i][j].rgbtBlue = averageValue;
            image[i][j].rgbtGreen = averageValue;
            image[i][j].rgbtRed = averageValue;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed, sepiaGreen, sepiaBlue;

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;
        if(sepiaRed > 255)
        {
            image[i][j].rgbtRed = 255;
        } else
        {
            image[i][j].rgbtRed = sepiaRed;
        }
        if(sepiaBlue > 255)
        {
            image[i][j].rgbtBlue = 255;
        } else
        {
            image[i][j].rgbtBlue = sepiaBlue;
        }
        if(sepiaGreen > 255)
        {
            image[i][j].rgbtGreen = 255;
        } else
        {
            image[i][j].rgbtGreen = sepiaGreen;
        }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < (width / 2); j++){
            RGBTRIPLE tmp;

            tmp = image[i][j];
            image[i][j] = image[i][(width - 1) - j];
            image[i][(width - 1) - j] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int totalRed, totalGreen, totalBlue;
            totalRed = totalGreen = totalBlue = 0;
            float counter = 0.0;

            for(int x = -1; x < 2; x++)
            {
                for(int y = -1; y < 2; y++)
                {
                    int currentX = i + x ;
                    int currentY = j + y ;

                    if(currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width -1))
                    {
                        continue;
                    }

                    counter++;

                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;
                }
                temp[i][j].rgbtRed = round(totalRed / counter);
                temp[i][j].rgbtGreen = round(totalGreen / counter);
                temp[i][j].rgbtBlue = round(totalBlue / counter);
            }
        }
    }
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
