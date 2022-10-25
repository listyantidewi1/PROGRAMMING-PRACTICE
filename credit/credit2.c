#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

    //prompt input
    long number = get_long ("Number: ");
    long n = number;
    long n_checktype = number;

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

    printf("Sum: %i\nLeftmost: %li\n", sum, n);

    if (sum % 10)
    {
        printf("INVALID\n");
    }
    else
    {
        //printf("Valid\n");
        long int number1 = n_checktype, number2 = n_checktype;
        while (n_checktype)
        {
            number2 = number1;
            number1 = n_checktype;
            n_checktype /= 10;
        }

        if (number2 == 34 || number2 ==37) {
            printf("AMEX");
        }

        if ((number2 >= 51 && number2 <= 55) || number2 == 22) {
            printf("MASTERCARD");
        }

        if (number2 >= 40 && number2 <=49) {
            printf("VISA");
        }
        else{
            //printf("INVALID");
        }
    }

}