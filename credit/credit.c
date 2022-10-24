#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long n, n_last, n_last2, underlined, not_underlined, sequence=100, sequence2=10;
    //prompt input
    long number = get_long ("Number: ");

    //checksum

    //get underlined digit of every other number
    //sequence: 100, 10000, ..
    //sequence * 100
    for(n = 0; n < 17; n++)
    {
        n_last = number % sequence;
        sequence = sequence * 100;
        //printf("n_last = %li\n", n_last);

        underlined = n_last;
        while (underlined >= 10)
        {
            underlined = underlined / 10;
        }
        //printf("underlined = %li\n", underlined);

        n_last2 = number % sequence2;
        sequence2 = sequence2 * 100;
        printf("n_last2 = %li\n", n_last2);

        not_underlined = n_last;
        while (not_underlined >= 10)
        {
           not_underlined = not_underlined / 10;
        }
        printf("not underlined = %li\n", not_underlined);

    }



}