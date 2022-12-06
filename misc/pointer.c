#include <stdio.h>

int* pn; //pointer pn - tidak menunjuk kemanapun
void square(int x);

int main(void)
{
    int x = 5; //deklarasi variabel x = 5
    square(x); //kirim nilai x ke n pada fungsi square
    printf("%i\n", *pn); //25
}

void square(int n) //x diterima oleh parameter n
{
    n = n * n; //dikalikan, hasilnya disimpan di n
    pn = &n; //pointer pn yang tadinya tidak menunjuk kemanapun, dibuat untuk menunjuk ke alamt n
}
