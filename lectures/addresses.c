#include <stdio.h>

int main(void)
{
    int n = 50; //deklarasi variabel n dengan nilai 50
    int *p = &n; //deklarasi pointer p dengan nilai alamat dari variabel n
    printf("%i\n", *p); //print nilai yang berapa di alamat p //go to address p and print its value in integer
    printf("%p\n", p); //print the balue of p which is the address of n
}