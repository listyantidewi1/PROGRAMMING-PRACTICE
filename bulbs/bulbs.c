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
    int b;
    while (message[i] != '\0')
    {
        //printf("i: %d\n", i);
        div = (int)message[i];
        b=0;
        do
        {
            //printf("b: %d\n", b);
            mod = div % 2;
            //printf("mod: %d\n", mod);
            div = div / 2;
            //printf("div: %d\n", div);
            binary[b] = mod;
            b++;
        }
        while(b < 8);

        //reverse and print the array

        int length = strlen(message);

        for (int k=0; k < length; k++)
        {
            int s = 7;
            //printf("k: %d\n", k);
            for (int r=0; r<8; r++)
            {
                //printf("r: %d\n", r);
                rev_binary[r] = binary[s];
                //printf("%d", rev_binary[r]);

                //printf("s: %d\n", s);
                s--;

            }
            //printf("\n");
        }

        for (int z=0; z<8; z++){
            print_bulb(rev_binary[z]);
        }


        i++;
        printf("\n");
    }

    //print array binary to test
    // for(int j=0; j<8; j++)
    // {
    //     printf("%d", rev_binary[j]);
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
