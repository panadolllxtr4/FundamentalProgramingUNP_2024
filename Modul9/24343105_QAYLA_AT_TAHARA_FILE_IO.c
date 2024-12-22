/*
Nama File       : 
Nama Programmer : Qayla At Thahara 24343105
Tgl Pembuatan   : 22 november 2024
Deskripsi       : 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defenisi struct untuk menyimpan data mahasiswa
struct Mahasiswa {
    char nama[50];
    char nim[15];
    char jurusan[30]; 
};

int main()
{
    struct Mahasiswa mahasiswa[100];
    int jumlahMahasiswa = 0;
    
    //membaca file input.txt
    FILE *inputFile = fopen("C:\\Users\\kilaa\\OneDrive\\Desktop\\Fundamental programing\\input.txt", "r");
    if (inputFile == NULL)
    {
        printf ("File input.txt tidak dapat dibuka!\n");
    }

    // membaca data dari file dan menyimpannya dalam array of struct
    while (fscanf(inputFile, "%s %s %s", mahasiswa[jumlahMahasiswa].nama, mahasiswa[jumlahMahasiswa]. nim, mahasiswa[jumlahMahasiswa].jurusan) !=EOF)
    {
        jumlahMahasiswa++;
    }
    fclose(inputFile);

    //menampilkan data yang telah dibaca
    printf("Data Mahasiswa dari File:\n");
    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        printf("Nama: %s, NIM: %s, Jurusan: %s\n", mahasiswa[i].nama, mahasiswa[i].nim, mahasiswa[i].jurusan);
    }

    //meminta intput data mahasiswa baru
    printf("\nMasukan data mahasiswa baru:\n");
    printf("Nama: ");
    scanf("%s", mahasiswa[jumlahMahasiswa].nama);
    printf("NIM: ");
    scanf("%s", mahasiswa[jumlahMahasiswa].nim);
    printf("Jurusan: ");
    scanf("%s", mahasiswa[jumlahMahasiswa].jurusan);
    jumlahMahasiswa++;

    //menulis seluruh data ke file output.txt
    FILE *outputFile = fopen("C:\\Users\\kilaa\\OneDrive\\Desktop\\Fundamental programing\\output.txt", "w");
    if (outputFile == NULL)
    {
        printf("File output.txt tidak dapat dibuat!\n");
        return 1;
    }

    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        fprintf(outputFile, "%s %s %s\n", mahasiswa[i].nama, mahasiswa[i].nim, mahasiswa[i].jurusan);
    }
    fclose(outputFile);

    printf("\nData berhasil disimpan ke output.txt!\n");

    return 0;
}