#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

    //prompt input
    long number = get_long ("Number: ");
    long n = number;

    //count number of digit
    int length = (number == 0) ? 1  : (log10(number) + 1);

    //Luhn Algorithm
    int sum = 0;
    sum = number % 10; //add checksum - get last digit
    number = number / 10; //chop last digit off

    while (number)
    {
        int temp = (number % 10) * 2; //get righmost digit and double it
        if (temp > 9)
        {
            temp = temp - 9;
        }
        sum = sum + temp; //add digit to sum
        number = number / 10; //chop rightmost digit off
        temp = number % 10; //get another rightmost digit
        sum = sum + temp; //add digit to sum
        number = number / 10; //chop right digit off
    }
    while (n > 10) //get leftmost digit
    {
        n = n /10;
    }

    //printf("Sum: %i\nLeftmost: %li\n", sum, n);

    if (sum % 10)
    {
        printf("Invalid\n");
    }else{
        printf("Valid\n");
    }


}