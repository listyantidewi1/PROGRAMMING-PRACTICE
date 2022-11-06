#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
    //formula: c = (p+k) %26
    //c = chipertext, k = key, p = plaintext
    string _argv = argv[1]; //copy argv[1] for further operations
    string plaintext, chipertext;
    int c, k;

    if ((argc == 2) && (only_digits(_argv))) //cipher only if command line args meet requirements
    {
        k = atoi(_argv); //convert literal string into integer
        plaintext = get_string("plaintext:  ");
        printf("ciphertext:  ");

        for (int i = 0, length = strlen(plaintext); i < length; i++)
        {
            //if the character is lowercase
            if (islower(plaintext[i]))
            {
                c = (plaintext[i] + k - 97) % 26 + 97;
                printf("%c", c);

            }
            //if the character is uppercase
            else if (isupper(plaintext[i]))
            {
                c = (plaintext[i] + k + 65) % 26 + 65;
                printf("%c", c);
            }
            //if the character is not alphabets
            else
            {
                printf("%c", plaintext[i]);
            }

        }
        printf("\n");

    }
    else
    {
        //handle innapropriate command line args
        printf("Usage: ./caesar key\n");
        return 1;
    }

}

bool only_digits(string s)
{
    bool check;
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (isdigit(s[i]))
        {
            check = true;
        }
        else
        {
            check = false;
        }

    }
    return check;
}