#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //getting user input
    string text = get_string("Text: ");

    //count the number of letters
    int num_letters = 0;
    int i = 0;

    while(text[i] != '\0')
    {
        if( ((text[i] >= 65) && (text[i] <= 90)) ||  ((text[i] >= 97) && (text[i] <= 122)))
        {
            num_letters++;
        }
        i++;
    }

    printf("Number of letters: %d", num_letters);

}