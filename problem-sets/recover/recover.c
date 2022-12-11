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
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (output_pointer != 0)
            {
                fclose(output_pointer);
            }

            sprintf(namafile, "%i.jpg", hitung_blok);
            output_pointer = fopen(namafile, "w");
            hitung_blok++;
        }
        if (output_pointer != 0)
        {

            fwrite(buffer, 512, 1, output_pointer);
        }
    }

    fclose(input_pointer);
    fclose(output_pointer);
    return 0;
}