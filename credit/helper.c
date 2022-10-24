#include <stdio.h>
#include <math.h>

int main(void)
{
    long number = get_long("Enter number: ");
    int count = (number == 0) ? 1  : (log10(number) + 1);

    for(n = 0; n < count/2; n++)
    {
        int i = (number % 10)*2;
    }

}