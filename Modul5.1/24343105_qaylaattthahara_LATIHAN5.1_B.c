/*
    Nama programmer : Qayla At Thahara (24343105)
    Nama File       : LATIHAN5.1_B
    Tgl pembuatan   : 25/Oktober/2024
    Deskripsi       : program ini menghitung keliling lingkaran 
*/

#include<stdio.h>

float hitungKelilingLingkaran(float jarijari)
{
    return 2 * 3.14 * jarijari;
}

int main()
{
    printf("===================================\n");
    printf("       MENGHITUNG KELILING\n");
    printf("===================================\n");
    printf(" nama programmer : qayla at thahara\n");
    printf(" NIM             : 24343105\n");  
    float jarijari;

    printf("Masukkan jari jari lingkaran: ");
    scanf("%f", &jarijari);

    float keliling = hitungKelilingLingkaran(jarijari);
    printf("Keliling lingkaran adalah: %.2f\n", keliling);

    return 0;
}