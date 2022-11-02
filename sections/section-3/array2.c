#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string sentence = get_string("Enter a sentence: ");

    for(int i = 0, length = strlen(sentence); i < length; i++)
    {
        printf("%c\n", sentence[i]);
    }
}