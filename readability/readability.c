#include <cs50.h>
#include <stdio.h>
#include <math.h>

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
    i = 0; //reset counter

    while (text[i] != '\0')
    {
        if(text[i] == 32) //whenever hits a space, increase the word count
        {
            num_words++;
        }
        i++;
    }

    printf("Number of words: %d\n", num_words);


    //count the number of sentences (whenever hits period (46), exclamation mark (33), or question mark (63))
    int num_sentences = 0;
    i = 0; //reset counter

    while (text[i] != '\0')
    {
        if((text[i] == 46) || (text[i] == 33) || (text[i] == 63)) //whenever hits period (46), exclamation mark (33), or question mark (63)
        {
            num_sentences++;
        }
        i++;
    }

    printf("Number of sentences: %d\n", num_sentences);

/*
index = 0.0588 * L - 0.296 * S - 15.8
where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
*/

float index = 0.0588 * (num_letters/num_words*100) - 0.0296 * (num_sentences/num_words*100) - 15.8;
printf("Grade %f\n", round(index));


}