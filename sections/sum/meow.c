#include <stdio.h>
#include <cs50.h>

int main(void)
{
    for (int i=0; i<10; i++)
    {
        printf("Meow in for loop\n");
    }

    int j = 0;
    while(j < 10)
    {
        printf("Meow in while loop\n");
        j++;
    }

    int k=0;
    do
    {
        printf("Meow in do-while loop\n");
        k++;
    }while(k < 10);

}