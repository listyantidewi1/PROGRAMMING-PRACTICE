#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    string plaintext;
    string _argv =  argv[1];
    if (argc == 2 && (strlen(_argv) == 26))
    {
        for (int i, length = strlen(_argv); i < length; i++)
        {
            if((_argv[i] < 65 || _argv[i] > 90) || (_argv[i] < 97 || _argv[i] > 122))
            {
                printf("Error\n");
                return 1;
            }
        }

        plaintext = get_string("plaintext:  ");

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