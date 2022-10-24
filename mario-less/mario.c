#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    int i, j, k; //initialize variables

    //ask for height
    while ((height <= 0) || (height > 8))
    {
        height = get_int("Height: ");
    }

    //loop for the numbers of rows
    for (i = 0; i < height; i++)
    {
        for (k = height; k > i + 1; k--) //loops for the numbers of spaces
        {
            printf(" ");
        }

        for (j = 0; j <= i; j++) //loops for the numbers of #
        {
            printf("#");
        }
        printf("\n"); //new row
    }

}