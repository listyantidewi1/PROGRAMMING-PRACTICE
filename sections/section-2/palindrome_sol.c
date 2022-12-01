#include<string.h>
#include<cs50.h>
#include<stdio.h>

int main(int argc, string argv[])
{

    // Fetch input from user
    string text = get_string("Input:  ");


    for (int i=0; i<strlen(text)/2; i++)
    {
        if (text[i] != text[strlen(text)-1-i])
        {
            printf("That's not a palindrome!\n");
            return 1;
        }
    }

    printf("It's a palindrome\n");
    return 0;

}