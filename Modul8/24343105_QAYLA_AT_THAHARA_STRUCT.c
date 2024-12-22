/* 	Nama File		: struct.c
	Programmer		: Qayla At Thahara 24343105
	Tgl. pembuatan	: 15 November 2024
	Deskripsi		: Membuat Struct
*/
#include <stdio.h>
#include <string.h>

//definisi tipe struct secara global
struct tanggal
{
    int hari, bulan, tahun;
};

struct mahasiswa
{
    char nama[30];
    int nim;
    struct tanggal tanggal_lahir;
};

// deklarasi variabel data_mahasiswa secara global
struct mahasiswa data_mahasiswa;

int main()
{
    printf("==============================\n");
    printf("\tMembuat struct\n");
	printf("==============================\n");
	printf("Nama : Qayla At Thahara \n");
	printf("Nim  : 24343105\n");
	printf("==============================\n");

    // mengisi data kedalam variabel struct data_mahasiswa
    strcpy(data_mahasiswa.nama, "Qayla At Thahara");
    data_mahasiswa.nim = 24343105;
    data_mahasiswa.tanggal_lahir.hari = 19;
    data_mahasiswa.tanggal_lahir.bulan = 10;
    data_mahasiswa.tanggal_lahir.tahun = 2005;

    // menampilkan data dalam struct data_mahasiswa
    printf("Nama Mahasiswa: %s\n", data_mahasiswa.nama);
    printf("Nomer Induk Mahasiswa: %d\n", data_mahasiswa.nim);
    printf("Tanggal Lahir: %d-%d-%d\n", data_mahasiswa.tanggal_lahir.hari,
           data_mahasiswa.tanggal_lahir.bulan,
           data_mahasiswa.tanggal_lahir.tahun);

    return 0;
}