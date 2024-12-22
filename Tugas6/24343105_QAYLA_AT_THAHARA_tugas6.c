/*
    Nama File       : soaltugas6.c
    Programmer      : Qayla At Thahara
    NIM             : 24343105
    Tgl.Pembuatan   : 22/11/2024
    Deskripsi       : Membuat program C untuk akses file dan memeriksa kecepatan program
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Untuk mengukur waktu eksekusi

#define MAX_BUFFER 100 // Untuk buffer untuk membaca file

// Fungsi untuk menghitung kata dalam file
int hitungKata(FILE *file) {
    char buffer[MAX_BUFFER];
    int jumlahKata = 0;
    char *kata;

    // Baca file baris per baris dan hitung jumlah kata
    while (fgets(buffer, MAX_BUFFER, file) != NULL) {
        kata = strtok(buffer, " \t\n"); // Tokenisasi string dengan delimiter spasi, tab, atau newline
        while (kata != NULL) {
            jumlahKata++; // Tambahkan jumlah kata
            kata = strtok(NULL, " \t\n"); // Ambil kata berikutnya
        } 
    }
    rewind(file); // Kembalikan posisi file ke awal
    return jumlahKata;
}

// Fungsi untuk menghitung jumlah karakter dan jumlah baris dalam file
void hitungKarakterBaris(FILE *file, int *jumlahKarakter, int *jumlahBaris) {
    char ch;
    *jumlahKarakter = 0;
    *jumlahBaris = 0;

    while ((ch = fgetc(file)) != EOF) {
        (*jumlahKarakter)++;
        if (ch == '\n') {
            (*jumlahBaris)++;
        }
    }
    // Jika file tidak diakhiri newline, tambahkan satu baris
    if (*jumlahKarakter > 0 && ch != '\n') {
        (*jumlahBaris)++;
    }
    rewind(file); // Kembalikan posisi file ke awal
}

int main() {
    printf("==================================================================\n");
    printf("Membuat program C untuk akses file dan memeriksa kecepatan program\n");
    printf("Programmer : Qayla At Thahara\n");
    printf("NIM : 24343105\n");
    printf("==================================================================\n");

    FILE *file;
    char namaFile[100];
    int jumlahKata, jumlahKarakter, jumlahBaris;
    clock_t start, end; // Untuk mengukur waktu
    double waktuEksekusi;

    // Meminta pengguna memasukkan nama file
    printf("Masukkan nama file: ");
    scanf("%s", namaFile);

    // Membuka file
    file = fopen(namaFile, "r");
    if (file == NULL){
        printf("Gagal membuka file %s.\n", namaFile);
        return 1;
    }

    // Mengukur waktu mulai
    start = clock();

    // Menghitung jumlah karakter dan jumlah baris dalam file
    hitungKarakterBaris(file, &jumlahKarakter, &jumlahBaris);

    // Menghitung jumlah kata dalam file
    jumlahKata = hitungKata(file);

    // Mengukur waktu selesai
    end = clock();

    // Menghitung waktu eksekusi dalam detik
    waktuEksekusi = (double)(end - start) / CLOCKS_PER_SEC;

    // Menutup file
    fclose(file);

    // Menampilkan hasil 
    printf("Jumlah karakter dalam file: %d\n", jumlahKarakter);
    printf("Jumlah baris dalam file: %d\n", jumlahBaris);
    printf("Jumlah kata dalam file: %d\n", jumlahKata);
    printf("Waktu eksekusi: %.5f detik\n", waktuEksekusi);

    return 0;
}
