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
    string _argv = argv[1];
    string plaintext, chipertext;
    int c, p, k;


    if ((argc == 2) && (only_digits(_argv)))
    {
        //printf("OK\n"); //debug
        k = atoi(_argv);
        plaintext = get_string("plaintext:  ");

        for(int i=0, length = strlen(plaintext); i<length; i++)
        {

            if(islower(plaintext[i]))
            {
                c = (plaintext[i]+k) % 26; //the result doesn't always fall into alphabet cat
                printf("c = %d\n", c); //debug
                if(c < 97)
                {
                    c += 97;
                    printf("c = %d\n", c); //debug
                }
                else if (c > 122)
                {
                    c -= 122;
                    printf("c = %d\n", c); //debug
                }

            }
            else
            {
                c = (plaintext[i]+k) % 26; //the result doesn't always fall into alphabet cat
                printf("c = %d\n", c); //debug
                if(c < 65)
                {
                    c += 65;
                    printf("c = %d\n", c); //debug
                }
                else if (c > 90)
                {
                    c -= 90;
                    printf("c = %d\n", c); //debug
                }
            }

        }

    }
    else
    {
        printf("Usage: ./caesar key\n");
    }

}

bool only_digits(string s)
{
    bool check;
    for (int i=0, length = strlen(s); i < length; i++)
    {
        if  (isdigit(s[i]))
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