#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //the average RGB values should stay the same for the old and new image
    //to make greyscale image, RGB values should be equal
    float avg_rgb_old;
    long tmp = 0;

    for(int i = 0; i < height; i++)
    {
        for(int j=0; j<width; j++){
            avg_rgb_old = round((double)(image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen)/3);
            //int avg = ceil(avg_rgb_old);
            //printf("%f\n", avg_rgb_old);
            image[i][j].rgbtRed = avg_rgb_old;
            image[i][j].rgbtBlue = avg_rgb_old;
            image[i][j].rgbtGreen = avg_rgb_old;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaB = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            int sepiaG = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaR = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);


            if(sepiaB > 255){
                image[i][j].rgbtBlue = 255;
            }else{
                image[i][j].rgbtBlue = sepiaB;
            }

            if(sepiaG > 255){
                image[i][j].rgbtGreen = 255;
            }else{
                image[i][j].rgbtGreen = sepiaG;
            }

            if(sepiaR > 255){
                image[i][j].rgbtRed = 255;
            }else{
                image[i][j].rgbtRed = sepiaR;
            }

            // image[i][j].rgbtBlue = (sepiaB > 255) ? 255 : sepiaB;
            // image[i][j].rgbtGreen = (sepiaG > 255) ? 255 : sepiaG;
            // image[i][j].rgbtRed = (sepiaR > 255) ? 255 : sepiaR;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //leftmost pixel should become the rightmost pixel
    //use swap
    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < width / 2; j++)
        {

            // //swap here

            RGBTRIPLE tmp[width][height];

            tmp[i][j] = image[i][j];
            image[i][j] = image[i][width-(j+1)];
            image[i][width-(j+1)] = tmp[i][j];

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];

    for (int i = 0; i < height; i++) //loop for each row
    {
        for (int j = 0; j < width; j++) //loop for each column
        {
            //store the sum of each color to calculate average
            float totalBlue = 0;
            float totalGreen = 0;
            float totalRed = 0;
            float count = 0;

            for (int r = -1; r < 2; r++) //loop for box around pixel - row
            {
                for (int c = -1; c < 2; c++) //loop for box around pixel - column
                {
                    if (i + r < 0 || i + r > height - 1) //if target box-pixel is out of image index - row
                    {
                        continue;
                    }

                    if (j + c < 0 || j + c > width - 1) //if target box-pixel is out of image index - column
                    {
                        continue;
                    }

                    totalBlue += image[i + r][j + c].rgbtBlue; //add the sum of box-colors
                    totalGreen += image[i + r][j + c].rgbtGreen;
                    totalRed += image[i + r][j + c].rgbtRed;
                    count++;
                }
            }

            tmp[i][j].rgbtBlue = round(totalBlue / count); //calculate average
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue; //assign new value 

            tmp[i][j].rgbtGreen = round(totalGreen / count);
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;

            tmp[i][j].rgbtRed = round(totalRed / count);
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
        }
    }

    return;
}