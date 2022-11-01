#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    string word = argv[1];
    printf((word[0]+7)%26);

    return 0;
}