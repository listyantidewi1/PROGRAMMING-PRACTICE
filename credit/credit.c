#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long n, first;
    //prompt input
    long number = get_long ("Number: ");

    //checksum

    //get two last digit
    long twoLast = number % 100;

    //get first digit
    first = twoLast;
    while (first >= 10)
    {
        first = first / 10;
    }

    //get first digit of every other number
    //sequence: 10, 100, 1000, 10000, ..
    //sequence * 10

    for(n = 0; n <)

    printf("Number: %li\n", number);
    printf("Twolast: %li\n", twoLast);
    printf("First: %li\n", first);


}