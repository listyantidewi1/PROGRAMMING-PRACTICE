#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    //check if lowercase's characters of a word is in alphabetical order. If yes print yes, if no, print no
    string s = get_string("String: ");

    for (int i = 0, length = strlen(s); i < length; i++)
    {
        s[i] = tolower(s[i]);
    }

    for (int i = 1, length = strlen(s); i < length; i++)
    {
        if (s[i] < s[i-1])
        {
            printf("No.\n");
            return 0;
        }
    }
    printf("Yes!\n");

}