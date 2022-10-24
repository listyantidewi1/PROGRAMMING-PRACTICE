#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long n, n_last, n_last2, underlined, not_underlined, sequence=100, sequence2=10;

    //prompt input
    long number = get_long ("Number: ");

    //count number of digit
    int count = (number == 0) ? 1  : (log10(number) + 1);
    int arr_underlined[count/2];
    //printf("num digit: %i", count);

    //checksum

    //get underlined digit / every other number start from the second to last digit
    //sequence: 100, 10000, ..
    //sequence * 100
    for(n = 0; n < count/2; n++)
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
        arr_underlined[n] = underlined;
    }

    //print array of underlined numbers
    for(n=0; n < (sizeof arr_underlined / sizeof arr_underlined[0]); n++)
    {
        printf("%i", arr_underlined[n]);
    }

    //multiply each array of underlined number by two, and calculate the sum
    int sum1 = 0;
    int sum2 =0;

    for (n=0; n < (sizeof arr_underlined / sizeof arr_underlined[0]); n++)
    {
        sum1 = arr_underlined[n]*2;
        sum2 = sum2 + sum1;
    }

    //print sum1
    printf("\nsum2 = %i\n", sum2);


}