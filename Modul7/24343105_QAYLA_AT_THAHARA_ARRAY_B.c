/*
    Nama File       : array B
    Nama Programmer : Qayla At Thahara 24343105
    Tgl Pembuatan   : 8 November 2024
    Deskripsi       : Menjumlahkan elemen array
*/

#include <stdio.h>

void judul() {
    printf("Nama  : Qayla At Thahara\n");
    printf("NIM   : 24343105\n");
}

int main() {
    judul();
    int angka[5] = {10, 20, 30, 40, 50};
    int jumlah = 0;
    for(int i = 0; i < 5; i++) {
        printf("Angka ke-%d: %d\n", i + 1, angka[i]);
    }
    for(int i = 0; i < 5; i++) {
        jumlah += angka[i];
    }
    printf("Jumlah semua elemen array: %d\n", jumlah);
    return 0;
}