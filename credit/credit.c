#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt input
    long number = get_long ("Number: ");

    //checksum
    long last = number % 10;
    printf("Last digit %li\n", last);

}