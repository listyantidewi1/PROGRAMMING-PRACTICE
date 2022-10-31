#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //formula: c = (p+k)%26
    //c = chipertext, k = key, p = plaintext
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
    }
    else
    {
        string cmd = argv[1];
        //check if the arguments are not number
        for (int i = 0, length = strlen(cmd); i < length; i++)
        {
            if ((cmd[i] < 48) || (cmd[i] > 57))
            {
                //printf("Usage: ./caesar key\n");
                break;
            }
        }
    }

}