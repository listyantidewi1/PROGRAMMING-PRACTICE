#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    //copy the valid characters into a new string
    string valid_word1 = "";
    string valid_word2 = "";
    int i;
    string temp="";

    while(word1[i] != '\0'){

        if(((word1[i] >= 65) && (word[i] <= 90)) ||  ((word1[i] >= 97) && (word[i] <= 122)))
        {
            temp = word[i];
            valid_word1 += temp;
        }
    }


    //make both strings uppercase


    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    //copy the word to _word
    string _word = "";
    strcpy(_word, word);

    //find the length of the word and store it
    int length = strlen(_word);



    return 0;
}
