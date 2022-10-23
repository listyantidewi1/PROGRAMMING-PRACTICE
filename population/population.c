#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_size = 0;
    int end_size = 0;
    int curr_size; //current population size
    int year = 0; //number of years to reach the end size
    int born = 0; //how many are born per year
    int death = 0; //how many are dead per year

    while (start_size < 9)
    {
        printf("Start size: ");
        scanf("%d", &start_size);

    }

    // TODO: Prompt for end size
    while (end_size <= 9)
    {
        printf("End size : ");
        scanf("%d", &end_size);
    }

    printf("\nStart size %d", start_size);
    printf("\nEnd size %d", end_size);

    curr_size = start_size;

    // TODO: Calculate number of years until we reach threshold

    while (curr_size < end_size)
    {
        born = curr_size / 3;
        death = curr_size / 4;
        curr_size = curr_size + born - death;
        year++;
    }

    // TODO: Print number of years
    printf("\nYear : %d\n", year);
}