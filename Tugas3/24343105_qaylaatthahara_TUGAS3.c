/*
    Nama programmer : Qayla At Thahara (24343105)
    Nama File       : LATIHAN5.1_C
    Tgl pembuatan   : 25/Oktober/2024
    Deskripsi       : program ini menampilkan permainan menara hanoi
*/

#include <stdio.h>

// Fungsi rekursif untuk Menara Hanoi
void hanoi(int n, char asal, char tujuan, char bantu) {
    if (n == 1) {
        printf("Pindahkan cakram 1 dari tiang %c ke tiang %c\n", asal, tujuan);
        return;
    }
    hanoi(n - 1, asal, bantu, tujuan);
    printf("Pindahkan cakram %d dari tiang %c ke tiang %c\n", n, asal, tujuan);
    hanoi(n - 1, bantu, tujuan, asal);
}

int main() {
    printf("===================================\n");
    printf("       PERMAINAN MENARA HANOI      \n");
    printf("===================================\n");
    printf(" nama programmer : qayla at thahara\n");
    printf(" NIM             : 24343105\n");    
    int cakram;

    // Meminta input jumlah cakram dari pengguna
    printf("Masukkan jumlah cakram: ");
    scanf("%d", &cakram);

    // Panggil fungsi rekursif untuk menara hanoi
    printf("Langkah-langkah untuk memindahkan %d cakram:\n", cakram);
    hanoi(cakram, 'A', 'C', 'B'); // 'A' adalah tiang asal, 'C' adalah tiang tujuan, 'B' adalah tiang bantu

    return 0;
}