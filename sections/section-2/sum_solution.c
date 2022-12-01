#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

int main (int argc, string argv[])
{
    // Check the number of inputs
    if (argc != 3)
    {
        printf("Usage Error\n");
        return 1;
    }

    // Check that every character in argv1 is a digit
    for (int i = 0, n = strlen(argv[1]); i< n ; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("argv1 is not a digit\n");
            return 0;
        }
    }

    // Check that every character in argv1 is a digit (forgive the copy-paste code)
    for (int i = 0, n = strlen(argv[2]); i< n ; i++)
    {
        if (isdigit(argv[2][i]) == 0)
        {
            printf("argv2 is not a digit\n");
            return 0;
        }
    }

    // Convert the strings to integers
    int first = atoi(argv[1]);
    int second = atoi(argv[2]);

    // Print the sum
    printf("The Sum is: %i\n", first + second);
}