#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

    //prompt input
    long number = get_long ("Number: ");

    //count number of digit
    int length = (number == 0) ? 1  : (log10(number) + 1);

    //Luhn Algorithm
    


}