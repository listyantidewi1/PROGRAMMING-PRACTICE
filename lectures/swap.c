#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y); //send the address of x and y to swap function
    printf("x is %i, y is %i\n", x, y);

}

void swap(int *a, int *b) //take the address of x and y, use it as pointers a and b (point towards the address of x and y)
{
    //swap the actual values!
    int tmp = *a;
    *a = *b;
    *b = tmp;
}