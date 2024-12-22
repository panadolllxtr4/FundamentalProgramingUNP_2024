/*  
     Nama File		: B.c
	Programmer		: Qayla At Thahara 
	Tgl. pembuatan	: 11/09/2024
    Deskripsi       : Menggabungkan Dua String
*/
#include <stdio.h>
#include <string.h>

// Deklarasi fungsi gabungkanString
void gabungkanString(char str1[], char str2[], char hasil[]);
void biodata(){
	printf("Menggabungkan Dua String\n");
	printf("==========================\n");
	printf("Nama : Qayla At Thahara\n");
	printf("Nim  : 24343105\n");
	printf("==========================\n");
}
int main() {
    biodata();
    char str1[100], str2[100], hasil[200];

    // Meminta input dua string dari pengguna
    printf("Masukkan string pertama: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Menghapus newline dari input

    printf("Masukkan string kedua: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Menghapus newline dari input

    // Memanggil fungsi gabungkanString dan menampilkan hasilnya
    gabungkanString(str1, str2, hasil);
    printf("Hasil penggabungan: %s\n", hasil);

    return 0;
}

// Definisi fungsi gabungkanString
void gabungkanString(char str1[], char str2[], char hasil[]) {
    strcpy(hasil, str1);   // Menyalin string pertama ke dalam hasil
    strcat(hasil, str2);   // Menggabungkan string kedua ke dalam hasil
}