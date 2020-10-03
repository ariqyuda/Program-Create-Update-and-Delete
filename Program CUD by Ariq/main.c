//Ariq Yuda Pratama//
//1908107010029//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Deklarasi typedef struct untuk keperluan beberapa fungsi//
typedef struct{
char kode[5];
char nama[30];
char tipe[30];
char status[30];
} Obat;

Obat tambah[255], cek[255], cari[255], hapus[255];

//Deklarasi fungsi yang digunakan//
void header();
void header1();
void login();
int menu();
int menu1();
void lanjut();
void tutup();
void kembali();
void TambahDataObat();
void TampilkanDataObat();
void CariDataObat();
void HapusDataObat();

int main(){

header();
login();

    int pilihan = menu();
    char pil_Lanjut[1];

    while (pilihan != 5){
        switch(pilihan){
            case 1:
                TampilkanDataObat();
                break;
            case 2:
                CariDataObat();
                break;
            case 3:
                TambahDataObat();
                break;
            case 4:
                HapusDataObat();
                break;
            default:
                printf("Pilihan tidak ditemukan");
                printf("\n");
                break;
        }
        pillanjut:
        printf("\nKembali ke Menu Utama ? (y/n) : ");
        scanf("%s", pil_Lanjut);
        if (strcmp(pil_Lanjut, "Y")==0 || strcmp(pil_Lanjut, "y")==0) {
            printf("\n");
            pilihan = menu1();
        } else if (strcmp(pil_Lanjut, "N")==0 || strcmp(pil_Lanjut, "n")==0){
            break;
        } else {
            printf("Pilihan Tidak Ada");
            goto pillanjut;
        }

    }

    printf("\nProgram Selesai");
    printf("\nThank for Using Me :)");

    return 0;

}

void header(){

printf("=========SELAMAT DATANG========\n");
printf("======DI PUSAT DATA APOTIK=====");

}

void header1(){

printf("\n========================");
printf("\n| SELAMAT DATANG ADMIN |");
printf("\n========================");

}


int menu(){

    header1();
    int input;
    printf("\n\nMAIN MENU");
    printf("\n========================");
    printf("\n1. Tampilkan data obat");
    printf("\n2. Cari data obat");
    printf("\n3. Tambah data obat");
    printf("\n4. Hapus data obat");
    printf("\n5. Selesai");
    printf("\n========================");
    printf("\nMasukkan pilihan = ");
    scanf("%d", &input);


    return input;
}

int menu1(){

    system("cls");
    header();
    int input;
    printf("\n\nMAIN MENU");
    printf("\n========================");
    printf("\n1. Tampilkan data obat");
    printf("\n2. Cari data obat");
    printf("\n3. Tambah data obat");
    printf("\n4. Hapus data obat");
    printf("\n5. Selesai");
    printf("\n========================");
    printf("\nMasukkan pilihan = ");
    scanf("%d", &input);


    return input;
}


//Implementasi fungsi untuk login//
void login(){

FILE *flog;
char login[200], id[15], pass[15];
char l;
int i=0;
char gabung[]="admin@root";
char biner[]="01100001 01100100 01101101 01101001 01101110 01000000 01110010 01101111 01101111 01110100";
int gabungg;

   flog=fopen("data/login.bin", "r");
       while (!feof(flog)){
        fgets(login, sizeof login, flog);
       }

    printf("\n\nSilahkan Login");
    kembali :
    printf("\nMasukkan username : "); scanf("%s", id);
    printf("Masukkan password : "); scanf("%s", pass);
    strcat(id, "@");
    strcat(id, pass);

    if (strcmp(id, gabung)==0){
        gabungg=strcmp(login, biner);
        if (gabungg == 0){
    }

    } else {
        printf("\nLogin Gagal");
        goto kembali;

    }

}

//implementasi fungsi untuk tambah data//
void TambahDataObat(){


FILE *fptr, *fptr1;
int jumlahdata=0, jumlahdata1=0;

fptr=fopen("data/data.txt", "a");

fptr1=fopen("data/data.txt", "a");
while (fscanf(fptr1, "%[^\n], %[^\n], %[^\n], %[^\n]\n", tambah[jumlahdata].kode, tambah[jumlahdata].nama, tambah[jumlahdata].tipe, tambah[jumlahdata].status)!=EOF){
}


fclose(fptr1);

printf("Masukkan Nama Obat\t: ");
scanf(" %[^\n]s", tambah[jumlahdata].nama);
printf("Masukkan Kode Obat\t: ");
scanf("%s", tambah[jumlahdata].kode);
printf("Masukkan Tipe Obat\t: ");
scanf(" %[^\n]s", tambah[jumlahdata].tipe);
printf("Masukkan Status Obat\t: ");
scanf(" %[^\n]s", tambah[jumlahdata].status);
fprintf(fptr, "\n%s, %s, %s, %s", tambah[jumlahdata].kode, tambah[jumlahdata].nama, tambah[jumlahdata
              ].tipe, tambah[jumlahdata].status);

fclose(fptr);

printf("\nData Berhasil Ditambahkan");



}

//implementasi fungsi untuk tampilkan data//
void TampilkanDataObat(){


printf("Tampilkan Data Obat\n\n");

FILE *tampil;
int jumlahdata=0;
int i=1;

tampil=fopen("data/data.txt", "r");
while (fscanf(tampil, "%[^,], %[^,], %[^,], %[^\n]\n", cek[jumlahdata].kode, cek[jumlahdata].nama, cek[jumlahdata].tipe, cek[jumlahdata].status)!=EOF){
        jumlahdata++;
printf("+------+-----------+---------------------------+---------------+-----------------+\n");
printf("|  NO  | Kode Obat |         Nama Obat         |   Tipe Obat   |   Status Obat   |\n");
printf("+------+-----------+---------------------------+---------------+-----------------+\n");
while (fscanf(tampil, "%[^,], %[^,], %[^,], %[^\n]\n", cek[jumlahdata].kode, cek[jumlahdata].nama, cek[jumlahdata].tipe, cek[jumlahdata].status)!=EOF){

printf("| %3d  |   %-5s   | %-26s|%-15s|%-17s|\n", jumlahdata, cek[jumlahdata].kode, cek[jumlahdata].nama, cek[jumlahdata].tipe, cek[jumlahdata].status);
        jumlahdata++;
        }
printf("+------+-----------+---------------------------+---------------+-----------------+\n");


fclose(tampil);

}
}

//implementasi fungsi untuk mencari data//
void CariDataObat(){


FILE *caridata;

printf("Cari Data Obat\n\n");
char carik[5];
int cariidata=0;
int hasil;
int test=0;
int n=0;

caridata=fopen("data/data.txt", "r");
ulang:
printf("Masukkan kode obat yang ingin dicari : ");
scanf("%s", cari[n].kode);

while (fscanf(caridata, "%[^,], %[^,], %[^,], %[^\n]\n", cek[cariidata].kode, cek[cariidata].nama, cek[cariidata].tipe, cek[cariidata].status)!=EOF){
         if (strcmp(cari[n].kode, cek[cariidata].kode)==0){
                test=1;
            printf("+------+-----------+---------------------------+---------------+-----------------+\n");
            printf("|  NO  | Kode Obat |         Nama Obat         |   Tipe Obat   |   Status Obat   |\n");
            printf("+------+-----------+---------------------------+---------------+-----------------+\n");
            printf("| %3d  |   %-5s   | %-26s|%-15s|%-17s|\n", cariidata, cek[cariidata].kode, cek[cariidata].nama, cek[cariidata].tipe, cek[cariidata].status);
            printf("+------+-----------+---------------------------+---------------+-----------------+\n");
         }
         cariidata++;


    }

printf("Data tidak ditemukan\n");
fclose(caridata);

}

void HapusDataObat(){

FILE *before, *after;
int m=0;
int hapusindata=0;
int test=0;

before=fopen("data/data.txt", "r");
after=fopen("data/baru.txt", "w");
printf("Masukkan kode obat yang ingin dihapus : ");
scanf("%s", hapus[m].kode);

while (fscanf(before, "%[^,], %[^,], %[^,], %[^\n]\n", cek[hapusindata].kode, cek[hapusindata].nama, cek[hapusindata].tipe, cek[hapusindata].status)!=EOF){
         if (strcmp(hapus[m].kode, cek[hapusindata].kode)!=0){
            fprintf(after, "%s, %s, %s, %s\n", cek[hapusindata].kode, cek[hapusindata].nama, cek[hapusindata].tipe, cek[hapusindata].status);
            hapusindata++;
         }

         else {
                test++;
                printf("\nData dengan kode %s telah dihapus\n", hapus[m].kode);
                printf("\nProses Penghapusan Sukses !\n");
         }
}
fclose(before);
fclose(after);
remove("data/data.txt");
rename("data/baru.txt", "data/data.txt");
}

void tutup(){
}

