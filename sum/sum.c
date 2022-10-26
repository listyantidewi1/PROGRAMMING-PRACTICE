#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //storage for two integers
    int a, b;

    //prompt user to input data
    a = get_int("Enter a value: ");
    b = get_int("Enter another value: ");

    //calculate and print the result
    printf("The sum of both numbers is: %i\n", a+b);
}