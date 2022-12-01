#include <stdio.h>
#include <cs50.h>

// Function Ptorotype
void makePositive(int a);


int main(void)
{
    int x = -5;

    printf("Before makePositive(): x is %i\n", x);

    makePositive(x);

    printf("After makePositive(): x is %i\n", x);

}

// This function squares n - why doesn't it work?
void makePositive(int a)
{
    printf("    Inside makePositive():  a is %i\n", a);

    // Check if a is negative - then make it positive
    if (a < 0)
    {
        a = a * -1;
    }

    printf("    Inside makePositive():  a is %i\n", a);
}