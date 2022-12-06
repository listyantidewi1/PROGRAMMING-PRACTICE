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
    for (int i=0; i<10; i++)
    {
        printf("Meow in for loop\n");
    }


    /*while dan do--while digunakan ketika kita tidak tahu (tidak peduli) berapa kali akan berulang
    tapi, kita tau (peduli) kapan dia berhenti berulang*/
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