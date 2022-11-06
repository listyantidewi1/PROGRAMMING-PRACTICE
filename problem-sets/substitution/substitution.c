#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    string plaintext, ciphertext = "";
    string _argv =  argv[1];
    if (argc == 2 && (strlen(_argv) == 26))
    {
        for (int i = 0, length = strlen(_argv); i < length; i++)
        {
            if((_argv[i] < 65 || _argv[i] > 90) || (_argv[i] < 97 || _argv[i] > 122))
            {
                printf("Error\n");
                return 1;
            }
        }

        plaintext = get_string("plaintext:  ");

        for (int i=0, length = strlen(plaintext); i < length; i++)
        {
            ciphertext[i] = _argv[i];
        }
        printf("ciphertext: ");

        for (int i=0, length = strlen(ciphertext); i < length; i++)
        {
            printf("%c", ciphertext[i]);
        }

        printf("\n");

    }
    else if (strlen(_argv) != 26)
    {
        printf("Key must contain 26 characters\n");
    }
    else
    {
        printf("Usage: ./substitution key\n");
    }
}