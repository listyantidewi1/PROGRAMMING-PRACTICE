//copying string by reference

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    //get a string
    string s = get_string("s: ");

    //copy string's address
    //because string variables store the address of the actual string, so we copy address instead of copying values
    //it actually make s and t point to the same address which store the first character of string
    string t = s;

    //capitalize first letter in string
    if (strlen(t) > 0) //use strlen to make sure string exists to avoid segmentation fault
    {
        t[0] = toupper(t[0]);
    }

    //print string twice
    printf("s: %s\n", s);
    printf("t: %s\n", t);
}