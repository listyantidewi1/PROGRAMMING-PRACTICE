'''
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
'''

# Fungsi untuk menghitung total atau rata-rata jam belajar per minggu
def calc_hours(hours, weeks, output):
    total_hours = sum(hours)
    if output == 'A':
        return total_hours / weeks
    return total_hours


# fungsi utama (main)
def main():
    # input jumlah minggu
    weeks = int(input("Berapa minggu Anda mengikuti BIMTEK?: "))
    hours = [] # array untuk menyimpan jumlah alokasi jam per minggu

    # iterasi untuk input alokasi jam belajar per minggu
    for i in range(weeks):
        hour = int(input(f"Alokasi belajar minggu ke-{i+1} (jam): "))
        hours.append(hour) # menambahkan data di array

    # output untuk option perhitungan T (total) atau A (average)
    # tampilkan option selama user belum memberi input yang benar
    output = ''
    while output not in ['T', 'A']:
        output = input("Ketik T untuk menghitung total jam belajar, atau A untuk mengetahui rata-rata jam belajar per minggu: ").upper()

    # panggil fungsi calc_hours untuk menghitung jumlah T atau A
    # tampilkan hasilnya
    print(f"{calc_hours(hours, weeks, output):.1f} jam")

# run
if __name__ == "__main__":
    main()
