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


    if ((argc == 2) || (only_digits(_argv)))
    {
        printf("OK\n");
    }
    else
    {
        printf("Usage: ./caesar key\n");
    }

}

bool only_digits(string s)
{
    for (int i=0, length = strlen(s); i < length; i++)
    {
        if(isalpha(s[i])){
            return false;
        }
        else
        {
            return true;
        }

    }
    return 0;
}