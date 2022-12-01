/*
 * Goal is to make a reverse() function that takes a string from the user
 * and prints the string in reverse order
 */

#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main(void)
{

    // Step 1: Get the String from the User
    string input = get_string("What To Reverse: ");

    // Step 2: Loop over the string (in reverse order) and print each letter
    for (int i=strlen(input); i>=0; i--)
    {
        printf("%c", input[i]);
    }


    printf("\n");
}

