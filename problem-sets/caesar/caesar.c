#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //formula: c = (p+k)%26
    //c = chipertext, k = key, p = plaintext
    while(argc==2)
    {
        string _argv = argv[1];
        int length = strlen(_argv);
        for (int i = 0; i < length; i++)
        {
            if ((_argv[i] < 48) || (_argv[i] > 57))
            {
                break;
            }
        }

    }

    printf("Usage: ./caesar key\n");

}