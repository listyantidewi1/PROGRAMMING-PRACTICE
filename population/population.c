#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_size = 0;
    int end_size = 0;
    int curr_size; //current population size
    int year = 0; //number of years to reach the end size

    while (start_size < 9)
    {
        start_size = get_int("Start size: ");
    }

    // TODO: Prompt for end size
    while (end_size < start_size)
    {
        end_size = get_int("End size: ");
    }

    curr_size = start_size;

    // TODO: Calculate number of years until we reach threshold

    while (curr_size < end_size)
    {
        curr_size = curr_size + (curr_size / 3) - (curr_size / 4);
        year++;
    }

    // TODO: Print number of years
    printf("Years: %i", year);
}