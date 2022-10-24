#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    long number = get_long("Enter number: ");
    int count = (number == 0) ? 1  : (log10(number) + 1);

    int i=0;

    while((i%2) != 0){
        int lastDigit = number % 10;
        printf("%i",lastDigit);
        i++;
    }

}