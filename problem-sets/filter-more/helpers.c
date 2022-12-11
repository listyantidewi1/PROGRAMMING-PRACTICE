#include "helpers.h"
#include "math.h"
#include "stdio.h"
#include "string.h"

// Prototype of function swap at the bottom
void swap(RGBTRIPLE *a, RGBTRIPLE *b);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //the average RGB values should stay the same for the old and new image
    //to make greyscale image, RGB values should be equal
    float avg_rgb_old;
    long temp = 0;

    for (int i = 0; i < height; i++) //iterate through each row
    {
        for (int j = 0; j < width; j++) //iterate through each column
        {
            avg_rgb_old = round((double)(image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3);
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
        for (int j = 0; j < width / 2; j++)
        {
            // RGBTRIPLE *a = &image[i][j];
            // RGBTRIPLE *b = &image[i][width - j -1];
            // RGBTRIPLE tmp;
            // //swap here
            // tmp = *a;
            // *a = *b;
            // *b = tmp;

            RGBTRIPLE tmp[width][height];
            swap(&image[i][j], &image[i][width - (j + 1)]);

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //There are a number of ways to create the effect of blurring or softening an image. For this problem, we’ll use the “box blur,” which works by taking each pixel and, for each color value, giving it a new value by averaging the color values of neighboring pixels.

    RGBTRIPLE temp[height][width];

    // copy image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Iterate through each row
    for (int i = 0; i < height; i++)
    {
        // Iterate through each column
        for (int j = 0; j < width; j++)
        {
            // Variable that hitungs how many numbers added to arrive at the sum
            int hitung = 0;

            // hitung total setiap warna
            double total_blue = 0;
            double total_green = 0;
            double total_red = 0;

            // Loop untuk memeriksa kotak -1 hingga + 1
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    // tambahkan hanya pixel yang berada di kotak
                    if (k >= 0 && l >= 0 && k < height && l < width)
                    {
                        total_blue += temp[k][l].rgbtBlue;
                        total_green += temp[k][l].rgbtGreen;
                        total_red += temp[k][l].rgbtRed;
                        hitung++;
                    }
                }
            }
            // set warna blur dengan rata2 kotak
            image[i][j].rgbtBlue = round(total_blue / hitung);
            image[i][j].rgbtGreen = round(total_green / hitung);
            image[i][j].rgbtRed = round(total_red / hitung);
        }
    }
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
    RGBTRIPLE temp[height][width];

    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gxBlue = 0;
            int gyBlue = 0;
            int gxGreen = 0;
            int gyGreen = 0;
            int gxRed = 0;
            int gyRed = 0;

            for (int r = -1; r < 2; r++)
            {
                for (int c = -1; c < 2; c++)
                {
                    if (i + r < 0 || i + r > height - 1)
                    {
                        continue;
                    }
                    if (j + c < 0 || j + c > width - 1)
                    {
                        continue;
                    }

                    gxBlue += image[i + r][j + c].rgbtBlue * gx[r + 1][c + 1];
                    gyBlue += image[i + r][j + c].rgbtBlue * gy[r + 1][c + 1];
                    gxGreen += image[i + r][j + c].rgbtGreen * gx[r + 1][c + 1];
                    gyGreen += image[i + r][j + c].rgbtGreen * gy[r + 1][c + 1];
                    gxRed += image[i + r][j + c].rgbtRed * gx[r + 1][c + 1];
                    gyRed += image[i + r][j + c].rgbtRed * gy[r + 1][c + 1];
                }
            }

            int blue = round(sqrt(gxBlue * gxBlue + gyBlue * gyBlue));
            int green = round(sqrt(gxGreen * gxGreen + gyGreen * gyGreen));
            int red = round(sqrt(gxRed * gxRed + gyRed * gyRed));

            if (blue > 255)
            {
                temp[i][j].rgbtBlue = 255;
            }
            else
            {
                temp[i][j].rgbtBlue = blue;
            }

            if (red > 255)
            {
                temp[i][j].rgbtRed = 255;
            }
            else
            {
                temp[i][j].rgbtRed = red;
            }

            if (green > 255)
            {
                temp[i][j].rgbtGreen = 255;
            }
            else
            {
                temp[i][j].rgbtGreen = green;
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }

    return;
}


//create swap function
// Function to swap two elements
void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
    RGBTRIPLE temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
