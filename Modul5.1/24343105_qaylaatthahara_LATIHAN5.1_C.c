/*
    Nama programmer : Qayla At Thahara (24343105)
    Nama File       : LATIHAN5.1_C
    Tgl pembuatan   : 25/Oktober/2024
    Deskripsi       : program ini menghitung faktorial 
*/

#include<stdio.h>

int hitungFaktorial(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    else{
        return n * hitungFaktorial(n - 1);
    }
}

int main()
{
    printf("===================================\n");
    printf("       MENGHITUNG FAKTORIAL\n");
    printf("===================================\n");
    printf(" nama programmer : qayla at thahara\n");
    printf(" NIM             : 24343105\n");    
    int n;

    printf("Masukkan bilangan bulat positif: ");
    scanf("%d", &n);

    int faktorial = hitungFaktorial(n);
    printf("Faktorial dari %d adalah: %d\n", n, faktorial);

    return 0;
}