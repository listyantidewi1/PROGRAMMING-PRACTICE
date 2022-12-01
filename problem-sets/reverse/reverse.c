#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int check_format(uint8_t header[]);
int get_block_size(uint8_t header[]);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 2)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Read header into an array
    // TODO #3
    uint8_t headers[HEADER_SIZE];
    fread(headers, HEADER_SIZE, 1, input);
    //fwrite(headers, HEADER_SIZE, 1, output);


    // Use check_format to ensure WAV format
    // TODO #4

    // Open output file for writing
    // TODO #5

    // Write header to file
    // TODO #6

    // Use get_block_size to calculate size of block
    // TODO #7

    // Write reversed audio to file
    // TODO #8
}

int check_format(uint8_t header[])
{
    // TODO #4
    return 0;
}

int get_block_size(uint8_t header[])
{
    // TODO #7
    return 0;
}