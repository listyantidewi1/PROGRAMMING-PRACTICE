#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //storage for 10 integers
    int number, sum=0; //number is for storing numbers we get from the user, sum is for storing sum
    int i = 0; //counter

    //prompt user to input data and calculate the sum
    while (i < 10)
    {
        number = get_int("Value: ");
        sum = sum + number; //add number to sum, one by one
        i++; //increase i by 1
    }

    //calculate and print the result
    printf("Sum is: %i\n", sum);
}