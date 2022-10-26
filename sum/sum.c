#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //storage for 10 integers
    int number, sum; //number 
    int i = 0; //counter

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