#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    //check if lowercase's characters of a word is in alphabetical order. If yes print yes, if no, print no

    string word = get_string("Enter a word: ");
    int wordcopy[strlen(word)];

    for(int i = 0, length = strlen(word); i < length+1; i++)
    {
        wordcopy[i] =  toupper(word[i]);
    }


    for(int i = 0, length = strlen(word); i < length+1; i++)
    {

            if(wordcopy[i] > wordcopy[i+1])
            {
                printf("No!");
                return 0;
            }
            else
            {
                printf("Yes!");
            }
        }

    }
