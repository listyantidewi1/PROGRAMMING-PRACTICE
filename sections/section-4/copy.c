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
    FILE *input = fopen("notes.txt", 'r);

    // Open/Create the output file

    // Going character by character, copy the input file to the output file
        // Somehow we will need to check for the end of the file

    // Close the input file
    // Close the output file

}

