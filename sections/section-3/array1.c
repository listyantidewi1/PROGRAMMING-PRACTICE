#include <stdio.h>
#include <cs50.h>

int main(void)
{
    const int SIZE = 5;

    int numbers[SIZE];
    numbers[0] = 1;

    for (int i=1; i<SIZE; i++)
    {
        numbers[i] = numbers[i-1] * 2;
    }

    for (int j = 0; j<SIZE; j++)
    {
        printf("%d\n", numbers[j]);
    }


}