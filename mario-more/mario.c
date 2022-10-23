#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    int i,j,k,l;

    while (height <= 0)
    {
        height = get_int("Height: ");
    }

    for(i=0; i<height; i++)
    {
        printf("\n");
        for(j=0; j<=i; j++)
        {
            printf("#");
        }
    }
    printf("\n");
}