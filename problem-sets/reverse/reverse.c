#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
uint8_t headers[HEADER_SIZE];
int16_t samples;

int check_format(uint8_t header[]);
int get_block_size(uint8_t header[]);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
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



    // Read header into an array
    // TODO #3

    fread(headers, HEADER_SIZE, 1, input);



    // Use check_format to ensure WAV format
    // TODO #4
    if(check_format(headers) == false)
    {
        return 1;
    }

    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Write header to file
    // TODO #6
    fwrite(headers, HEADER_SIZE, 1, output);

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(headers);

    // Write reversed audio to file
    // TODO #8
    int16_t samples_copy[block_size];
    while (fread(&samples, sizeof(int16_t), 1, input))
    {
        //samples *= factor;
        //fwrite(&samples,  1, sizeof(int16_t), output);
        for (int i = 0, size = sizeof[samples_copy]; i < size; i++)
        {
            samples_copy[size - i] = samples;
            fwrite(&samples_copy[size-i], sizeof(int16_t), 1, ouput);
        }

    }


    // Close files
    fclose(input);
    fclose(output);

    return 0;
}

int check_format(uint8_t header[])
{
    // TODO #4
    uint8_t riff[4] = {82,73,70,70};
    uint8_t wave[4] = {87,65,86,69};

    for (int i = 0; i < 4; i++)
    {
        if (!(header[i] == riff[i]))
        {
            return false;
            //return 1;
        }
    }

    for (int i = 8; i < 12; i++)
    {
        if (!(header[i] ==  wave[i - 8]))
        {
            return false;
            //return 1;
        }

    }

    return true;
    return 0;
}

int get_block_size(uint8_t header[])
{
    // TODO #7
    int number_of_channels = header[23] * 256 + header[22];
    int byte_per_sample = header[35] / 8;
    int block_size = number_of_channels * byte_per_sample;

    return block_size;
}