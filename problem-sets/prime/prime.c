#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    int isPrime;
    // TODO
    for (int i = 1; i < number; i++)
    {
        isPrime = number % i;
        printf("sisa dari %i dibagi %i : %i", number, i, isPrime);
        if (isPrime > 0){
            break;
        }
        return true;
    }
    return false;
}