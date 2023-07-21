#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // minta user untuk memasukkan nilai x
    int x = get_int("x: ");

    // minta user untuk memasukkan nilai y
    int y = get_int("y: ");

    // lakukan penjumlahan x dengan y
    printf("%i\n", x + y);
}
