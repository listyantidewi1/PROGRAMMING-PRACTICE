#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    //get a string
    char *s = get_string("s: ");

    //allocate memory for another string
    char *t = malloc(strlen(s) + 1); //one extra memory for \0

    //copy string into memory, including '\0'
    for (int i = 0; i <= strlen(s); i++)
    {
        t[i] = s[i];
    }

    //capitalize copy
    t[0] = toupper(t[0]);

    //print strings
    printf("s: %s\n", s);
    printf("t: %s\n", t);
}