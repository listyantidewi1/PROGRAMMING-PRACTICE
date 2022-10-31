#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;
int binary[8];
int div, mod;

void print_bulb(int bit);

int main(void)
{
    // TODO
    //prompt user inputs (string)
    string message = get_string("Message: ");

    //extract each character and convert to binary
    int i = 0;
    while (message[i] != '\0')
    {
        do
        {
            div = message[i] / 2;
            mod = message[i] % 2;
            binary[i] = mod;
        }
        while(div >= 1);

        i++;
    }

    //print array binary to test
    for(int j=0; j<8; j++)
    {
        printf("%d", binary[j]);
    }

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
