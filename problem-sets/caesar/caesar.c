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

    char lower[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    char upper[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};


    if ((argc == 2) && (only_digits(_argv)))
    {
        //printf("OK\n"); //debug
        k = atoi(_argv);
        plaintext = get_string("plaintext:  ");

        for(int i=0, length = strlen(plaintext); i<length; i++)
        {

            if(islower(plaintext[i]))
            {
                c = (plaintext[i]+k) % 26; //the result doesn't always fall into alphabet cat, the use of %26 assumes A=0, etc
                printf("c = %d\n", c); //debug
                printf("%c\n",lower[c]);


            }
            else
            {
                c = (plaintext[i]+k) % 26; //the result doesn't always fall into alphabet cat
                printf("c = %d\n", c); //debug
                printf("%c\n",upper[c]);

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