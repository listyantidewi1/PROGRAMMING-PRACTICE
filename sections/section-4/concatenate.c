#include<stdio.h>
#include<stdlib.h> // Malloc() and free()
#include<string.h>
#include<cs50.h>   // For get_string

char *concatenate(char *first, char *second);

int main(void)
{
    //Get the starting strings from the user
    char *first = get_string("First String: ");
    char *second = get_string("Second String: ");

    // A new char * for the result string
    char *combined;

    combined = concatenate(first, second);

    printf("Combined they are %s\n", combined);

    // Free the Memory
    free(combined);
    return 0;
}


char *concatenate(char *first, char *second)
{
    // Todo 1: Determine how much space we need
    char *string1 = malloc(sizeof(string));

    // Todo 2: Malloc() the appropriate amount of space

    // Todo 3: Copy the contents of first

    // Todo 4: Copy the contents of second

    // Todo 5: Return the result
}
