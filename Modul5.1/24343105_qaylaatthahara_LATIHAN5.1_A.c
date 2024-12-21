/*
    Nama programmer : Qayla At Thahara (24343105)
    Nama File       : LATIHAN5.1_A
    Tgl pembuatan   : 25/Oktober/2024
    Deskripsi       : program ini menghitung luas persegi panjang
*/

#include<stdio.h>

int hitungLuasPersegiPanjang(int panjang, int lebar)
{
    return panjang * lebar;
}

int main()
{
    printf("===================================\n");
    printf("         MENGHITUNG LUAS\n");
    printf("===================================\n");
    printf(" nama programmer : qayla at thahara\n");
    printf(" NIM             : 24343105\n");  
    int panjang, lebar;

    printf("Masukkan panjang: ");
    scanf("%d", &panjang);
    printf("Masukkan lebar: ");
    scanf("%d", &lebar);

    int luas = hitungLuasPersegiPanjang(panjang, lebar);
    printf("Luas persegi panjang adalah: %d\n", luas);

    return 0;
}