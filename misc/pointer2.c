#include <stdio.h>

void square(int *x); //prototipe fungsi

int main(void)
{
    int x = 5; //deklarasi variabel x = 5
    square(&x); //kirim alamat x ke *n di fungsi square
    printf("%i\n", x); //25
}

void square(int *n) //alamat x diterima oleh *n
{
    *n = *n * *n; //apapun yg ada di alamat x atau di *n, dikuadratkan
}