#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%s\n", s); //print the string value at the address of s

    //print the addresses of each character in string
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
}