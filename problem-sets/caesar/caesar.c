#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //formula: c = (p+k)%26
    //c = chipertext, k = key, p = plaintext

    string cmd = argv[1];


    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        //check if the arguments are not number
        for (int i = 0, length = strlen(cmd); i < length; i++)
        {
            if ((cmd[i] < 48) || (cmd[i] > 57))
            {
                printf("Usage: ./caesar key\n");
                return 1;
                break;
            }
            //if it is a number, check if it's negative
            else if(cmd[i] < 0)
            {
                break;
            }
            else
            {
                int k = atoi(cmd);
                //printf("OK inside for\n"); //debug
                //implement caesar
                //formula: c = (p+k)%26
                //c = chipertext, k = key, p = plaintext

                string plaintext = get_string("plaintext:  ");


            }
        }


        //printf("OK outside for\n"); //debug

    }

}