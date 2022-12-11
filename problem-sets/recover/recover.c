#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //jika argumen tidak sama dengan dua (argumen tidak pas)
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    char *input = argv[1];
    FILE *input_pointer = fopen(input, "r"); //cek apakah file bisa dibuka
    if (input_pointer == NULL)
    {
        printf("Unable to open file\n");
        return 1;
    }

    int hitung_blok = 0; //untuk menghitung jumlah blok
    FILE *output_pointer = NULL;
    char namafile[8];
    uint8_t buffer[512];

    while (fread(buffer, 512, 1, input_pointer))
    {
        /*
        Even though JPEGs are more complicated than BMPs, JPEGs have “signatures,” patterns of bytes that can distinguish them from other file formats. Specifically, the first three bytes of JPEGs are 0xff 0xd8 0xff from first byte to third byte, left to right. The fourth byte, meanwhile, is either 0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, or 0xef. Put another way, the fourth byte’s first four bits are 1110.
        */
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {
            if (output_pointer != 0)
            {
                fclose(output_pointer);
            }

            sprintf(namafile, "%03i.jpg", hitung_blok);
            output_pointer = fopen(namafile, "w");
            hitung_blok = hitung_blok + 1;
        }
        if (output_pointer != 0)
        {

            fwrite(buffer, 512, 1, output_pointer);
        }
    }

    fclose(input_pointer); //tutup file input
    fclose(output_pointer); //tutup file output
    return 0;
}