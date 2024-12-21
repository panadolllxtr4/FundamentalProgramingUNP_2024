/*
    Nama    : Qayla At Thahara
    NIM     : 24343105
    Program : program ini menmapilkan game menebak angka dengan tingkat kesulitan 
*/

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void easy(int *highScore){
        printf("EASY (0-50)");
    int angkaTebakan, tebakan, kesempatan;
    int score;

    srand(time(0));

        angkaTebakan = rand() % 50 + 1;
        kesempatan = 5;

        while (kesempatan > 0){
            printf("\nMasukkan tebakan anda: ");
            scanf("%d", &tebakan);

            if(tebakan > angkaTebakan){
                printf("Tebakan anda terlalu tinggi!");
            }else if(tebakan < angkaTebakan){
                printf("Tebakan anda terlalu rendah!");
            }else{
                score = kesempatan * 10;
                printf("Selamat! anda menebak dengan benar!\n");
                if(score > *highScore){
                    *highScore = score;
                    printf("SCORE TERTINGGI BARU: %d\n", *highScore);
                }
                break;
            }
            kesempatan--;
            printf("Kesempatan tersisa: %d\n", kesempatan);
        }
        if(kesempatan == 0){
            printf("Maaf, anda kehabisan kesempatan. Angka yang benar adalah %d.\n", angkaTebakan);
        }
}

void medium(int *highScore){
        printf("MEDIUM (0-100)");
    int angkaTebakan, tebakan, kesempatan;
    int score;
    srand(time(0));

        angkaTebakan = rand() % 100 + 1;
        kesempatan = 5;

        while (kesempatan > 0){
            printf("\nMasukkan tebakan anda: ");
            scanf("%d", &tebakan);

            if(tebakan > angkaTebakan){
                printf("Tebakan anda terlalu tinggi!");
            }else if(tebakan < angkaTebakan){
                printf("Tebakan anda terlalu rendah!");
            }else{
                score = kesempatan * 10;
                printf("Selamat! anda menebak dengan benar!\n");
                if(score > *highScore){
                    *highScore = score;
                    printf("SCORE TERTINGGI BARU: %d\n", *highScore);
                }
                break;
            }
            kesempatan--;
            printf("Kesempatan tersisa: %d\n", kesempatan);
        }
        if(kesempatan == 0){
            printf("Maaf, anda kehabisan kesempatan. Angka yang benar adalah %d.\n", angkaTebakan);
        }
}

void hard(int *highScore){
    printf("HARD (0-200)");
    int angkaTebakan, tebakan, kesempatan;
    int score;
    srand(time(0));

        angkaTebakan = rand() % 200 + 1;
        kesempatan = 5;
        
        while (kesempatan > 0){
            printf("\nMasukkan tebakan anda: ");
            scanf("%d", &tebakan);

            if(tebakan > angkaTebakan){
                printf("Tebakan anda terlalu tinggi!");
            }else if(tebakan < angkaTebakan){
                printf("Tebakan anda terlalu rendah!");
            }else{
                score = kesempatan * 10;
                printf("Selamat! anda menebak dengan benar!\n");
                if(score > *highScore){
                    *highScore = score;
                    printf("SCORE TERTINGGI BARU: %d\n", *highScore);
                }
                break;
            }
            kesempatan--;
            printf("Kesempatan tersisa: %d\n", kesempatan);
        }
        if(kesempatan == 0){
            printf("Maaf, anda kehabisan kesempatan. Angka yang benar adalah %d.\n", angkaTebakan);
        }
}

int main(){
    int level;
    int highScore = 0;
    while (1) {
        printf("============= Game tebak angka =============\n");
        printf("Nama : QAYLA AT THAHARA\n");
        printf("NIM	 : 24343105\n");
        printf("============================================\n");
        printf("Score tertinggi: %d\n", highScore);
        printf("Pilih tingkat kesulitan\n");
        printf("1. Easy\n");
        printf("2. Medium\n");
        printf("3. Hard\n");
        printf("4. Keluar\n");
        scanf("%d", &level);

        switch (level) {
            case 1:
                easy(&highScore);
                break;
            case 2:
                medium(&highScore);
                break;
            case 3:
                hard(&highScore);
                break;
            case 4:
                printf("Keluar dari program.\n");
                exit(0);
            default:
                printf("Opsi tidak valid, coba lagi.\n");
        }
    }

    return 0;
}