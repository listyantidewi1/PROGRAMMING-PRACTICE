#include "helpers.h"
#include "math.h"
#include "stdio.h"
#include "string.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //the average RGB values should stay the same for the old and new image
    //to make greyscale image, RGB values should be equal
    float avg_rgb_old;
    long temp = 0;

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

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //leftmost pixel should become the rightmost pixel
    //use swap
    //printf("%lu\n",sizeof(image));

    for (int i = 0; i < height; i++)
    {
        for(int j=0; j< width; j++)
        {
            
        }
    }


    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //There are a number of ways to create the effect of blurring or softening an image. For this problem, we’ll use the “box blur,” which works by taking each pixel and, for each color value, giving it a new value by averaging the color values of neighboring pixels.

    return;
}

// Detect edges
//maybe use transpose matrix
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}