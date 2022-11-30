/*
Program to Copy an input file.

Usage ./copy infile outfile
*/


#include <stdio.h>

int main(int argc, char *argv[])
{
    // Make sure we have 3 arguments
    if (argc != 3)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }

    // Open the input file
    FILE *input = fopen(argv[1], "r");

    // Open/Create the output file
    FILE *output = fopen(argv[2], "w");

    // Going character by character, copy the input file to the output file
        // Somehow we will need to check for the end of the file

        char c;
        
        while(1==fread(&c, 1, 1, input))
        {
            //printf("%c\n", c);
            fwrite(&c, 1, 1, output);
        }

    // Close the input file
    fclose(input);
    // Close the output file
    fclose(output);

}

