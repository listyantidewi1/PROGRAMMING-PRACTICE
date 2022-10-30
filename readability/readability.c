#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //getting user input
    string text = get_string("Text: ");

    //count the number of letters
    int num_letters = 0;
    int i = 0;

    while (text[i] != '\0')
    {
        if( ((text[i] >= 65) && (text[i] <= 90)) ||  ((text[i] >= 97) && (text[i] <= 122))) //whenever hits alphabet, increase the word counts
        {
            num_letters++;
        }
        i++;
    }

    printf("Number of letters: %d\n", num_letters);


    //count the number of words;

    int num_words = 1;
    i = 0;

    while (text[i] != '\0')
    {
        if(text[i] == 32) //whenever hits a space, increase the word count
        {
            num_words++;
        }
        i++;
    }

    printf("Number of words: %d\n", num_words);

}