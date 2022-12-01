/*
Program to Copy an input file.

Usage ./copy infile outfile
*/

// Contains all the file-manipulating functions, fopen(), fclose(), fread(), fwrite()...
#include <stdio.h>
#include <ctype.h>

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

    char c;

    // Continuously read 1 byte from the file and then write that byte
    while (1==fread(&c, 1, 1, input))
    {
        // Convert the character c to upper case
        c = toupper(c);

        fwrite(&c, 1, 1, output);
    }

    // Close the input file
    fclose(input);

    // Close the output file
    fclose(output);
}

