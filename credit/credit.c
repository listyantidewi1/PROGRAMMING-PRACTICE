#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long n, underlined, not_underlined, sequence=100, sequence2=10;
    //prompt input
    long number = get_long ("Number: ");

    //checksum

    //get underlined digit of every other number
    //sequence: 100, 10000, ..
    //sequence * 100
    for(n = 0; n < 17; n++)
    {
        twoLast = number % sequence;
        sequence = sequence * 100;
        //printf("twolast = %li\n", twoLast);

        underlined = twoLast;
        while (underlined >= 10)
        {
            underlined = underlined / 10;
        }
        //printf("underlined = %li\n", underlined);
    }



}