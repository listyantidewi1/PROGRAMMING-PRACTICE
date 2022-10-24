#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long n, first, second, sequence=100, sequence2=10;
    //prompt input
    long number = get_long ("Number: ");

    //checksum


    //get first digit of every other number
    //sequence: 100, 10000, ..
    //sequence * 100
    for(n = 0; n < 17; n++)
    {
        twoLast = number % sequence;
        sequence = sequence * 100;
        //printf("twolast = %li\n", twoLast);

        first = twoLast;
        while (first >= 10)
        {
            first = first / 10;
        }
        //printf("first = %li\n", first);
    }



}