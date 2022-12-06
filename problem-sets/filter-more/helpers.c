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
    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            // RGBTRIPLE *a = &image[i][j];
            // RGBTRIPLE *b = &image[i][width - j -1];
            // RGBTRIPLE tmp;
            // //swap here
            // tmp = *a;
            // *a = *b;
            // *b = tmp;

            RGBTRIPLE tmp[width][height];

            tmp[i][j] = image[i][j];
            image[i][j] = image[i][(width-1)-j]; //this cause segmentation error
            image[i][j-width-1] = tmp[i][j];

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
    //tranpose
    //swap:
    //0,1 with 1,0
    //0,2 with 2,0
    //2,1 with 1,2
    //keep
    //0,0
    //1,0
    //2,2
    return;
}


//create swap function
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}