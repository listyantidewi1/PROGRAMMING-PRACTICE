//header = pustaka = library
#include<string.h>
#include<cs50.h>
#include<stdio.h>

int main(void)
{
    // Fetch the name from the user
    name = get_string("What is Your Name:");

    // Calculate the length of the input
    int length = len(name);

    // Print the intro text
    printf("Your Initials Are: ");

    // Iterate over every character in the name
    for (int i = 0; i < length; i++)
    {
        // If the character is uppercase - print it
        if (isupper(i)){
            printf("%i", i);    // Incomplete line
        }
    }

    printf("\n");
}
