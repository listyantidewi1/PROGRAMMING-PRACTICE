#include <cs50.h>
#include <stdio.h>
//#include <stdin.h>

int main(void){
    string name = get_string("What's your name? \n");
    printf("Hello, %s\n", name);
}