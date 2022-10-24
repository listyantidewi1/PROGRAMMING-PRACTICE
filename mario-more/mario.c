#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    int i, j, k, l;

    while ((height <= 0) || (height > 8))
    {
        height = get_int("Height: ");
    }

    for (i = 0; i < height; i++)
    {


        for (k = height; k > i+1; k--)
        {
            printf(" ");
        }

        for (j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }

}