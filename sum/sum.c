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
        number = get_int("Enter a number: ");
        sum = sum + number;
        i++;
    }

    //calculate and print the result
    printf("The sum of all of the numbers is: %i\n", sum);
}