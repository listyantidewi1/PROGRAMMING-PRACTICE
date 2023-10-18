#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

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
    if (number <= 1)
    {
        return false; // 0 and 1 are not prime numbers
    }
    if (number <= 3)
    {
        return true; // 2 and 3 are prime numbers
    }
    if (number % 2 == 0 || number % 3 == 0)
    {
        return false; // Any other multiple of 2 or 3 is not prime
    }

    // Check for prime by testing divisibility up to the square root of the number
    for (int i = 5; i * i <= number; i += 6)
    {
        if (number % i == 0 || number % (i + 2) == 0)
        {
            return false;
        }
    }

    return true;
}
