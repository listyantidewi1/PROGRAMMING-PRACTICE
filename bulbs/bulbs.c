#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;
int binary[8];
int rev_binary[8];
int div, curr_div, mod, curr_mod;

void print_bulb(int bit);

int main(void)
{
    // TODO
    //prompt user inputs (string)
    string message = get_string("Message: ");

    //extract each character and convert to binary
    int i = 0;
    int b = 0;
    while (message[i] != '\0')
    {
        div = (int)message[i];
        do
        {
            div = div / 2;
            mod = div % 2;
            binary[b] = mod;
            b++;
        }
        while(b < 8);

        //reverse and print the array
        int s = 7;
        int length = strlen(message);

        for (int k=0; k < length; k++)
        {
            for (int r=0; r<8; r++)
            {
                rev_binary[r] = binary[s];
                printf("%d", rev_binary[r]);
                s--;
            }
            printf("\n");
        }

        i++;
    }

    //print array binary to test
    // for(int j=0; j<8; j++)
    // {
    //     printf("%d", binary[j]);
    // }

}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
