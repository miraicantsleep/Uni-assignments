#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char nama[101];
    char nrp[101];
    char angkatan[101];
    char umur[101];
    char asal[101];
} Mahasiswa;

void showData(Mahasiswa a, int i) {
    printf("Nama Mhs-%d\t: %s\n", i, a.nama);
    printf("NRP Mhs-%d\t: %s\n", i, a.nrp);
    printf("Angkatan Mhs-%d\t: %s\n", i, a.angkatan);
    printf("Umur Mhs-%d\t: %s\n", i, a.umur);
    printf("Asal Mhs-%d\t: %s\n\n", i, a.asal);
}

int main() {
    int n;
    scanf("%d\n", &n);

    Mahasiswa a[n];
    for(int i = 0; i < n; i++) {
        gets(a[i].nama);
        gets(a[i].nrp);
        gets(a[i].angkatan);
        gets(a[i].asal);
        gets(a[i].umur);
    }

    int apa;
    while(scanf("%d", &apa) && apa != -1) {
        if(apa == 1) {
            char data[101];
            scanf(" %s", data);

            bool ketemu = false;
            printf("===== HASIL PENCARIAN =====\n");
            for(int i = 0; i < n; i++) {
                if(strstr(a[i].nama, data) != NULL || strstr(a[i].nrp, data) != NULL || 
                   strstr(a[i].angkatan, data) != NULL || strstr(a[i].umur, data) != NULL ||
                   strstr(a[i].asal, data) != NULL) {
                    ketemu = true;
                    showData(a[i], i);
                }
            }
            if(!ketemu) {
                printf("DATA TIDAK DITEMUKAN\n\n");
            }
        }
        else if(apa == 2) {
            int x, y;
            scanf("%d %d", &x, &y);

            Mahasiswa temp = a[x];
            a[x] = a[y];
            a[y] = temp;
        }
        else {
            char tukar[101];
            int x, y;
            scanf(" %s %d %d", tukar, &x, &y);

            char temp[101];
            if(strcmp(tukar, "nama") == 0) {
                strcpy(temp, a[x].nama);
                strcpy(a[x].nama, a[y].nama);
                strcpy(a[y].nama, temp);
            }
            else if(strcmp(tukar, "nrp") == 0) {
                strcpy(temp, a[x].nrp);
                strcpy(a[x].nrp, a[y].nrp);
                strcpy(a[y].nrp, temp);
            }
            else if(strcmp(tukar, "angkatan") == 0) {
                strcpy(temp, a[x].angkatan);
                strcpy(a[x].angkatan, a[y].angkatan);
                strcpy(a[y].angkatan, temp);
            }
            else if(strcmp(tukar, "umur") == 0) {
                strcpy(temp, a[x].umur);
                strcpy(a[x].umur, a[y].umur);
                strcpy(a[y].umur, temp);
            }
            else {
                strcpy(temp, a[x].asal);
                strcpy(a[x].asal, a[y].asal);
                strcpy(a[y].asal, temp);
            }
        }
    }

    printf("===== DATA MAHASISWA =====\n");
    for(int i = 0; i < n; i++) {
        showData(a[i], i);
    }

    return 0;
}