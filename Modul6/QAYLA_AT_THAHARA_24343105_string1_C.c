/*  
     Nama File		: C.c
	Programmer		: Qayla At Thahara (24343105)
	Tgl. pembuatan	: 11/09/2024
    Deskripsi       : Membandingkan Dua String
*/
#include <stdio.h>
#include <string.h>

// Deklarasi fungsi bandingkanString
int bandingkanString(char str1[], char str2[]);
void biodata(){
	printf("Membandingkan Dua String\n");
	printf("==========================\n");
	printf("Nama : Qayla At Thahara\n");
	printf("Nim  : 24343105\n");
	printf("==========================\n");
}
int main() {
    biodata();
    char str1[100], str2[100];

    // Meminta input dua string dari pengguna
    printf("Masukkan string pertama: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Menghapus newline dari input

    printf("Masukkan string kedua: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Menghapus newline dari input

    // Memanggil fungsi bandingkanString dan menampilkan hasil perbandingan
    int hasil = bandingkanString(str1, str2);
    if (hasil == 0) {
        printf("Kedua string sama.\n");
    } else {
        printf("Kedua string tidak sama.\n");
    }

    return 0;
}

// Definisi fungsi bandingkanString
int bandingkanString(char str1[], char str2[]) {
    return strcmp(str1, str2);
}