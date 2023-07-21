#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // tanyakan ukuran grid ke pengguna, dan simpan di variabel n
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1);

    // Print balok
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}