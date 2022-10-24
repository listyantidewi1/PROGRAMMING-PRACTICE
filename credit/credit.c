#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long n, first, sequence=10;
    //prompt input
    long number = get_long ("Number: ");

    //checksum

    //get two last digit
    long twoLast = number % 100;

    //get first digit


    //get first digit of every other number
    //sequence: 10, 1000, ..
    //sequence * 100

    for(n = 0; n < 17; n++)
    {
        twoLast = number % sequence;
        sequence = sequence * 100;
        printf("twolast = %li\n", twoLast);

        first = twoLast;
        while (first >= 10)
        {
            first = first / 10;
        }
        printf("first = %li\n", first);
    }

    // printf("Number: %li\n", number);
    // printf("Twolast: %li\n", twoLast);
    // printf("First: %li\n", first);


}