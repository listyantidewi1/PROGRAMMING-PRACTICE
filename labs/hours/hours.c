/*
-----Jam Belajar------
Tujuan:
1. Belajar menggunakan array
2. Menggunakan array sebagai paramater dalam sebuah fungsi
3. Menambahkan nilai dalam sebuah perulangan/loop
4. Pembagian bilangan bulat dan casting tipe data

Deskripsi Soal:
Misalkan Anda mengikuti sebuah BIMTEK Informatika dan menghabiskan waktu setiap minggu untuk belajar. Anda mungkin bertanya-tanya berapa jam yang Anda habiskan untuk mempelajari materi Informatika, meliputi rata-rata atau totalnya! Dalam program ini, Anda akan menyelesaikan fungsi yang menghitung, berdasarkan masukan pengguna, jumlah total jam atau jumlah rata-rata jam dalam jumlah hari tertentu, yang dialokasikan untuk belajar materi pada BIMTEK.

Petunjuk
Untuk menjumlahkan angka dalam array, Anda mungkin ingin menginisialisasi variabel ke nol terlebih dahulu. Setelah itu, Anda dapat menggunakan perulangan yang menambahkan setiap nilai dalam array ke variabel tersebut.
Pastikan untuk memperhatikan apa yang terjadi jika Anda membagi dua bilangan bulat saat menghitung rata-rata!
*/


#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

// Prototype fungsi calc_hours
float calc_hours(int hours[], int weeks, char output);


// Fungsi main
int main(void)
{
    // input lama BIMTEK (dalam minggu)
    int weeks = get_int("Berapa minggu Anda mengikuti BIMTEK?: ");
    // array untuk menyimpan nilai alokasi jam belajar per minggu
    int hours[weeks]; // [10, 2, 6]

    // iterasi untuk input alokasi jam belajar per minggu
    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Alokasi belajar minggu ke - %i+1 (jam): ", i);
    }

    // variabel (tipe karakter) untuk menyimpan output
    char output;

    // output untuk option perhitungan T (total) atau A (average)
    do
    {
        // tampilkan option selama user belum memberi input yang benar
        output = toupper(get_char("Ketik T untuk menghitung total jam belajar, atau A untuk mengetahui rata-rata jam belajar per minggu: "));
    }
    while (output != 'T' && output != 'A');

    // panggil fungsi calc_hours untuk menghitung jumlah T atau A
    // tampilkan hasilnya
    printf("%.1f jam\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    int total_hours = 0;
    for (int current_week = 0; current_week < weeks; current_week++)
    {
        // hitung total jam
        total_hours += hours[current_week];
    }
    if (output == 'A')
    {
        // hitung rata-rata
        return (total_hours / (float) weeks);
    }
    // kembalikan nilai hasil perhitungan
    return total_hours;
}
