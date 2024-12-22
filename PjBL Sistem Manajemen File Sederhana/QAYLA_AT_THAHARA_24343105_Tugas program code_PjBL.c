/*
nama file       : project based learning
nama programmer : Qayla At Thahara (24343105)
deskripsi       : program ini mengelola sistem manajemen file sederhana
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//deklarasi fungsi
void displayMenu();
void logToFile(FILE *outputFile, const char *message);
void logCreatedFile(const char *filename);
void removeFileFromLog(const char *filename);
void createFile();
void writeFile();
void readFile();
void searchFile();
void deleteFile();
void processFile(const char *inputFilename, const char *outputFilename);
void renameFile();
void viewFileList();

//fungsi untuk menampilkan menu
void displayMenu() {
    printf("1. Tambah File\n");
    printf("2. Isi File\n");
    printf("3. Baca File\n");
    printf("4. Cari File\n");
    printf("5. Hapus File\n");
    printf("6. Proses file (dari input.txt ke output.txt)\n");
    printf("7. Ubah Nama File\n");
    printf("8. Tampilkan Semua File\n");
    printf("9. Keluar\n");
    printf("Pilih Opsi: ");
}

//fungsi untuk mencatat log ke file
void logToFile(FILE *outputFile, const char *message) {
    if (outputFile != NULL) {
        fprintf(outputFile, "%s\n", message);
    }
}

//fungsi untuk mencatat nama file yang dibuat
void logCreatedFile(const char *filename) {
    FILE *logFile = fopen("file_log.txt", "a");
    if (logFile != NULL) {
        fprintf(logFile, "%s\n", filename);
        fclose(logFile);
    } else {
        printf("Gagal mencatat file ke log.\n");
    }
}


//fungsi untuk menghapus nama file dari log
void removeFileFromLog(const char *filename) {
    FILE *logFile = fopen("file_log.txt", "r");
    if (logFile == NULL) {
        return;
    }

    FILE *tempFile = fopen("file_log_temp.txt", "w");
    if (tempFile == NULL) {
        fclose(logFile);
        return;
    }
    
    char line[256];
    while (fgets(line, sizeof(line), logFile)) {
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, filename) != 0) {
            fprintf(tempFile, "%s\n", line);
        }
    }

    fclose(logFile);
    fclose(tempFile);

    remove("file_log.txt");
    rename("file_log_temp.txt", "file_log.txt");
}

//fungsi untuk membuat file baru
void createFile() {
    char filename[100];
    clock_t start_time, end_time;
    start_time = clock(); // Mencatat waktu mulai
    printf("Masukkan nama file yang ingin dibuat: ");
    getchar(); // Membersihkan buffer
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Menghapus karakter newline

    FILE *file = fopen(filename, "w");
    if (file) {
        printf("\nFile \"%s\" berhasil dibuat.\n", filename);
        fclose(file);
        logCreatedFile(filename);  // Mencatat file yang dibuat
    } else {
        printf("\nGagal membuat file \"%s\".\n", filename);
    }
    end_time = clock(); // Mencatat waktu selesai
    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nProses selesai dalam waktu %.2f detik.\n", duration);
}

//fungsi untuk mengisi file
void writeFile() {
    char filename[100], content[500];

    clock_t start_time, end_time;
    start_time = clock(); // Mencatat waktu mulai

    printf("Masukkan nama file yang ingin ditulis: ");
    getchar(); // Membersihkan buffer
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Menghapus karakter newline

    FILE *file = fopen(filename, "a");
    if (file) {
        printf("Masukkan isi file: ");
        fgets(content, sizeof(content), stdin);
        fprintf(file, "%s", content);
        fclose(file);
        printf("\nBerhasil menulis ke file \"%s\".\n", filename);
    } else {
        printf("\nGagal membuka file \"%s\".\n", filename);
    }

    end_time = clock(); // Mencatat waktu selesai
    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nProses selesai dalam waktu %.2f detik.\n", duration);
}

//fungsi untuk membaca isi file
void readFile() {
    char filename[100];

    clock_t start_time, end_time;
    start_time = clock(); // Mencatat waktu mulai

    printf("Masukkan nama file yang ingin dibaca: ");
    getchar(); // Membersihkan buffer
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    FILE *file = fopen(filename, "r");
    if (file) {
        char ch;
        printf("Isi file \"%s\":\n", filename);
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
        }
        fclose(file);
    } else {
        printf("\nFile \"%s\" tidak ditemukan.\n", filename);
    }

    end_time = clock(); // Mencatat waktu selesai
    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nProses sel esai dalam waktu %.2f detik.\n", duration);
}

//fungsi untuk mencari file berdasarkan nama
void searchFile() {
    char filename[100];
    clock_t start_time, end_time;
    start_time = clock(); // Mencatat waktu mulai

    printf("Masukkan nama file yang ingin dicari: ");
    getchar(); // Membersihkan buffer
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Menghapus karakter newline

    FILE *file = fopen(filename, "r");
    if (file) {
        printf("\nFile \"%s\" ditemukan.\n", filename);
        fclose(file);
    } else {
        printf("\nFile \"%s\" tidak ditemukan.\n", filename);
    }

    end_time = clock(); // Mencatat waktu selesai
    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nProses selesai dalam waktu %.2f detik.\n", duration);
}

//fungsi untuk menghapus file berdasarkan nama
void deleteFile() {
    char filename[100];

    clock_t start_time, end_time;
    start_time = clock(); // Mencatat waktu mulai

    printf("Masukkan nama file yang ingin dihapus: ");
    getchar(); // Membersihkan buffer
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    if (remove(filename) == 0) {
        printf("\nFile \"%s\" berhasil dihapus.\n", filename);
        removeFileFromLog(filename);  // Menghapus nama file dari log
    } else {
        printf("\nGagal menghapus file \"%s\".\n", filename);
    }

    end_time = clock(); // Mencatat waktu selesai
    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nProses selesai dalam waktu %.2f detik.\n", duration);
}

//fungsi untuk memindahkan proses file dari input.txt ke  output.txt
void processFile(const char *inputFilename, const char *outputFilename) {
    clock_t start_time, end_time;
    start_time = clock(); // Mencatat waktu mulai

    FILE *inputFile = fopen(inputFilename, "r");
    FILE *outputFile = fopen(outputFilename, "w");

    if (inputFile == NULL) {
        printf("\nGagal membuka file input \"%s\".\n", inputFilename);
        return;
    }
    if (outputFile == NULL) {
        printf("\nGagal membuka file output \"%s\".\n", outputFilename);
        fclose(inputFile);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), inputFile)) {
        line[strcspn(line, "\n")] = '\0'; // Menghapus newline

        // Memproses perintah berdasarkan isi baris
        if (strncmp(line, "buatfile:", 9) == 0) {
            char filename[100];
            sscanf(line + 9, "%s", filename);
            FILE *newFile = fopen(filename, "w");
            if (newFile) {
                fclose(newFile);
                char logMessage[200];
                snprintf(logMessage, sizeof(logMessage), "File %s dibuat.", filename);
                logToFile(outputFile, logMessage);
                logCreatedFile(filename);  // Mencatat file yang dibuat
            } else {
                printf("\nGagal membuat file %s.\n", filename);
            }
        } else if (strncmp(line, "isifile:", 8) == 0) {
            char filename[100], content[200];
            if (sscanf(line + 8, "%s \"%[^\"]\"", filename, content) == 2) {
                FILE *file = fopen(filename, "a");
                if (file) {
                    fprintf(file, "%s\n", content);
                    fclose(file);
                    char logMessage[200];
                    snprintf(logMessage, sizeof(logMessage), "File %s diisi dengan: %s", filename, content);
                    logToFile(outputFile, logMessage);
                } else {
                    printf("\nGagal membuka file %s.\n", filename);
                }
            } else {
                printf("Format isifile tidak valid: %s\n", line);
            }
        } else if (strncmp(line, "hapusfile:", 10) == 0) {
            char filename[100];
            sscanf(line + 10, "%s", filename);
            if (remove(filename) == 0) {
                char logMessage[200];
                snprintf(logMessage, sizeof(logMessage), "File %s dihapus.", filename);
                logToFile(outputFile, logMessage);
                removeFileFromLog(filename);  // Menghapus nama file dari log
            } else {
                printf("\nGagal menghapus file %s.\n", filename);
            }
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    end_time = clock(); // Mencatat waktu selesai
    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nProses selesai dalam waktu %.2f detik. Hasil dicatat di file \"%s\".\n", duration, outputFilename);
}

//fungsi untuk mengubah nama file
void renameFile() {
    char oldFilename[100], newFilename[100];

    clock_t start_time, end_time;
    start_time = clock(); // Mencatat waktu mulai

    printf("Masukkan nama file yang ingin diubah: ");
    getchar(); // Membersihkan buffer
    fgets(oldFilename, sizeof(oldFilename), stdin);
    oldFilename[strcspn(oldFilename, "\n")] = '\0'; // Menghapus karakter newline

    printf("\nMasukkan nama baru untuk file: ");
    fgets(newFilename, sizeof(newFilename), stdin);
    newFilename[strcspn(newFilename, "\n")] = '\0'; // Menghapus karakter newline

    if (rename(oldFilename, newFilename) == 0) {
        printf("\nFile \"%s\" berhasil diubah menjadi \"%s\".\n", oldFilename, newFilename);
        removeFileFromLog(oldFilename);  // Menghapus nama lama dari log
        logCreatedFile(newFilename);     // Mencatat nama file baru ke log
    } else {
        printf("\nGagal mengubah nama file \"%s\".\n", oldFilename);
    }

    end_time = clock(); // Mencatat waktu selesai
    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nProses selesai dalam waktu %.2f detik.\n", duration);
}

//fungsi untuk menampilkan semua file yang sudah ditambahkan
void viewFileList() {
    clock_t start_time, end_time;
    start_time = clock(); // Mencatat waktu mulai
    FILE *logFile = fopen("file_log.txt", "r");
    if (logFile == NULL) {
        printf("Tidak ada file yang tercatat.\n");
        return;
    }

    char filename[100];
    printf("Daftar file yang telah dibuat:\n");
    while (fgets(filename, sizeof(filename), logFile)) {
        filename[strcspn(filename, "\n")] = '\0';  // Menghapus newline
        printf("%s\n", filename);
    }

    fclose(logFile);
    
    end_time = clock(); // Mencatat waktu selesai
    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nProses selesai dalam waktu %.2f detik.\n", duration);
}

//fungsi utama
int main() {
    int choice;

    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("File akan disimpan ke direktori: %s\n", cwd);
    } else {
        perror("getcwd() error");
        return 1;
    }
    const char *newDirectory = "D:\\coolyeah\\pjbl.10 fundamental programming";
    if (chdir(newDirectory) == 0) {
    printf("Direktori kerja berhasil diubah ke: %s\n", newDirectory);
    } else {
        perror ("Gagal mengubah direktori kerja");
    }

    while(1) {
    printf("=============================================\n");
    printf("             Selamat Datang di\n");
    printf("       Sistem Manajemen File Sederhana\n");
    printf("=============================================\n");
    printf("Nama Programmer : Qayla At Thahara\n");
    printf("NIM             : 24343105\n");
    printf("Mata Kuliah     : Fundamental Programming\n");
    printf("Dosen Pengampu  : Vikri Aulia, S.Pd, M.Kkom\n");
    printf("=============================================\n");

    do{
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                    createFile();
                    break;
                case 2:
                    writeFile();
                    break;
                case 3:
                    readFile();
                    break;
                case 4:
                    searchFile();
                    break;
                case 5:
                    deleteFile();
                    break;
                case 6:
                    processFile("input.txt", "output.txt");
                    break;
                case 7:
                    renameFile();
                    break;
                case 8:
                    viewFileList();
                    break;
                case 9:
                    printf("Keluar dari program.\n");
                    exit(0);
                default:
                    printf("Opsi tidak valid, coba lagi.\n");
        }
    } while (choice != 9);

    }
    return 0;
}