#include <cs50.h>
#include <stdio.h>

long factorial(long);   // Prototype of our factorial function.  Note the long instead of int!

// The main function is complete as is!
int main(void)
{

    int input = get_int("What should we factorialize: ");
    printf("The factorial of %i is %li\n", input, factorial(input));

}

// Implementation of the factorial function
long factorial(long n)
{
    // Base Case
    if (n==0){
        return 1;
    }

    // TODO 1: Recursive Call

    // TODO 2: Return the correct value

}