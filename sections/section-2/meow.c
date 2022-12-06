#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //for loop
    /*
        ketika kita sudah tahu perulangan akan berulang berapa kali

        string n = {"red", "green", "blue"};
        sizeof(array) atau strlen(string)
    */
    for (int i=10; i>0; i--)
    {
        printf("Meow in for loop\n");
    }


    /*while dan do--while digunakan ketika kita tidak tahu (tidak peduli) berapa kali akan berulang
    tapi, kita tau (peduli) kapan dia berhenti berulang

    contoh implementasi:
    - retry pada game (scrabble), program akan terus meminta argumen (jumlah huruf) yang cocok (5 -8) sampai user memberi argumen yang benar. Tidak bisa dipastikan berapa kali user akan retry memberi argumen sampai benar
    */

   /*bisa saja tidak pernah dieksekusi jika kondisi tidak dipenuhi*/
    int j = 0;
    while(j < 10)
    {
        printf("Meow in while loop\n");
        
    }

    /*pasti dilakukan dulu 1x, baru cek kondisi*/
    int k=100;
    do
    {
        printf("Meow in do-while loop\n");
        k++;
    }while(k < 10);

}