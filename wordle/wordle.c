#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// each of our text files contains 1000 words
#define LISTSIZE 1000

// values for colors and score (EXACT == right letter, right place; CLOSE == right letter, wrong place; WRONG == wrong letter)
#define EXACT 2
#define CLOSE 1
#define WRONG 0

// ANSI color codes for boxed in letters
#define GREEN   "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW  "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED     "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET   "\e[0;39m"

// user-defined function prototypes
string get_guess(int wordsize);
int check_word(string guess, int wordsize, int status[], string choice);
void print_word(string guess, int wordsize, int status[]);

int main(int argc, string argv[])
{
    // ensure proper usage
    // TODO #1
    if(argc == 2)
    {

    int wordsize = 0;

    // ensure argv[1] is either 5, 6, 7, or 8 and store that value in wordsize instead
    // TODO #2
    //53, 54, 55, 56
    if((strcmp(argv[1], "5")) || (strcmp(argv[1], "6")) || (strcmp(argv[1], "7")) || (strcmp(argv[1], "8")))
    {
        //wordsize = argv[1];
        //argv[1] return a string of number or its ascii decimal
        //you have to convert it to an integer of the literal string
        //example: 5 string is 53 decimal -> 53 - 48 = 5

        wordsize = atoi(argv[1]);
        //printf("wordsize: %i", wordsize);
    }
    else
    {
        printf("Error: wordsize must either 5, 6, 7, or 8\n");
    }

    // open correct file, each file has exactly LISTSIZE words
    char wl_filename[6];
    sprintf(wl_filename, "%i.txt", wordsize);
    FILE *wordlist = fopen(wl_filename, "r");
    if (wordlist == NULL)
    {
        printf("Error opening file %s.\n", wl_filename);
        return 1;
    }

    // load word file into an array of size LISTSIZE
    char options[LISTSIZE][wordsize + 1];

    for (int i = 0; i < LISTSIZE; i++)
    {
        fscanf(wordlist, "%s", options[i]);
    }

    // pseudorandomly select a word for this game
    srand(time(NULL));
    string choice = options[rand() % LISTSIZE];
    //string choice = "abcde";

    // allow one more guess than the length of the word
    int guesses = wordsize + 1;
    bool won = false;

    // print greeting, using ANSI color codes to demonstrate
    printf(GREEN"This is WORDLE50"RESET"\n");
    printf("You have %i tries to guess the %i-letter word I'm thinking of\n", guesses, wordsize);

    // main game loop, one iteration for each guess
    for (int i = 0; i < guesses; i++)
    {
        // obtain user's guess
        string guess = get_guess(wordsize);

        // array to hold guess status, initially set to zero
        int status[wordsize];

        // set all elements of status array initially to 0, aka WRONG
        // TODO #4
        for(int j=0; j<wordsize; j++)
        {
            status[j] = 0;
        }

        // Calculate score for the guess
        int score = check_word(guess, wordsize, status, choice);

        printf("Guess %i: ", i + 1);

        // Print the guess
        print_word(guess, wordsize, status);

        // if they guessed it exactly right, set terminate loop
        if (score == EXACT * wordsize)
        {
            won = true;
            break;
        }
    }

    // Print the game's result
    // TODO #7
    if (won)
    {
        printf("You wins!");
    }
    else
    {
        printf("%s", choice);
    }

    // that's all folks!
    return 0;
    }
    else
    {
        printf("Usage: ./wordle wordsize\n");
    }
}

string get_guess(int wordsize)
{
    string guess = "";

    // ensure users actually provide a guess that is the correct length
    // TODO #3
    while(strlen(guess) != wordsize)
    {
        guess = get_string("Input a %i-letter word: ", wordsize);
    }

    return guess;
}

int check_word(string guess, int wordsize, int status[], string choice)
{
    int score = 0;

    // compare guess to choice and score points as appropriate, storing points in status
    // TODO #5
    //EXACT, CLOSE, WRONG
    for(int i = 0; i < wordsize; i++)
    {
        // if(guess[i] == choice[i])
        // {
             printf("i: %d\n", i); //debug
        //     int curr_score = EXACT;
        //     //still needs a break to avoid checking this letter again
        //     status[i] = curr_score;
        //     score += curr_score;
        //     printf("exact found, this one scores: %d\n",curr_score); //debug
        //     //break;
        // }
        // else
        // {
        //     for(int j=0; j<wordsize; j++)
        //     {
        //         printf("j: %d\n", j); //debug
        //         for(int k=0; k<wordsize; k++)
        //         {
        //             printf("k: %d\n", k); //debug
        //             if(guess[j] == choice[k])
        //             {
        //                 int curr_score = CLOSE;
        //                 status[j] = curr_score;
        //                 score += curr_score;
        //                 printf("close found, this one scores: %d\n",curr_score);
        //             }
        //         }
        //     }
        // }

        for(int j=0; j < wordsize; j++)
        {
            printf("j: %d\n", j); //debug
            if(guess[i] == choice[i])
            {
                int curr_score = EXACT;
                status[i] = curr_score;
                score += curr_score;
                printf("exact found, this one scores: %d\n",curr_score); //debug
                break;
            }
            else if(guess[i] == choice[j])
            {
                int curr_score = CLOSE;
                status[j] = curr_score;
                score += curr_score;
                printf("close found, this one scores: %d\n",curr_score);
            }
        }

    }
    printf("total score: %d\n",score);


    // HINTS
    // iterate over each letter of the guess
        // iterate over each letter of the choice
            // compare the current guess letter to the current choice letter
                // if they're the same position in the word, score EXACT points (green) and break so you don't compare that letter further
                // if it's in the word, but not the right spot, score CLOSE point (yellow)
        // keep track of the total score by adding each individual letter's score from above

    return score;
}

void print_word(string guess, int wordsize, int status[])
{
    // print word character-for-character with correct color coding, then reset terminal font to normal
    // TODO #6
    for(int i=0; i<wordsize; i++)
    {
        if(status[i] == 2)
        {
            printf(GREEN"%c",guess[i]);
        }
        else if(status[i] == 1)
        {
            printf(YELLOW"%c", guess[i]);
        }
        else if(status[i] == 0)
        {
            printf(RED"%c", guess[i]);
        }
    }
    printf(RESET);
    printf("\n");
    return;
}
