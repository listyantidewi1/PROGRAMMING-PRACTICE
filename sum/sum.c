#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //storage for two integers
    int number, sum;
    int i = 0;

    //prompt user to input data
    while (i < 10)
    {
        number = get_int("Value: ");
        sum = sum + number;
        i++;
    }

    //calculate and print the result
    printf("Sum is: %i\n", sum);
}