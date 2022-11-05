#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //formula: c = (p+k) %26
    //c = chipertext, k = key, p = plaintext
    string _argv = argv[1];


    if ((argc != 2) || (isalpha(_argv[1])))
    {
        printf("Usage: ./caesar key\n");
    }
    else
    {
        printf("OK\n");
    }


}