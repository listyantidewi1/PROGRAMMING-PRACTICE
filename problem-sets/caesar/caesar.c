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
                if(c < 97)
                {

                }
                else if (c > 122)
                {
                    
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