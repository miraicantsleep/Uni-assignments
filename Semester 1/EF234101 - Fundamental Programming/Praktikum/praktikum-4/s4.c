#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct mahasiswa
{
    char nama[50];
    char NRP[50];
    char angkatan[50];
    char umur[50];
    char asal[80];
};

void printData(struct mahasiswa index, int i)
{
    printf("Nama Mhs-%d\t: %s\n", i, index.nama);
    printf("NRP Mhs-%d\t: %s\n", i, index.NRP);
    printf("Angkatan Mhs-%d\t: %s\n", i, index.angkatan);
    printf("Umur Mhs-%d\t: %s\n", i, index.umur);
    printf("Asal Mhs-%d\t: %s\n\n", i, index.asal);
}

void find(struct mahasiswa data[], int size, char check[])
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (strstr(data[i].nama, check) != NULL ||
            strstr(data[i].NRP, check) != NULL ||
            strstr(data[i].angkatan, check) != NULL ||
            strstr(data[i].umur, check) != NULL ||
            strstr(data[i].asal, check) != NULL)
        {
            found = true;
            printData(data[i], i);
            // break;
        }
    }
    if (!found)
    {
        printf("DATA TIDAK DITEMUKAN\n\n");
    }
}

void swapUrut(struct mahasiswa *ptr1, struct mahasiswa *ptr2)
{
    struct mahasiswa temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void swapVal(char *ptr1, char *ptr2)
{
    char temp[100];
    strcpy(temp, ptr1);
    strcpy(ptr1, ptr2);
    strcpy(ptr2, temp);
}

int main()
{
    int N;
    scanf("%d\n", &N);
    struct mahasiswa structArr[N];
    for (int i = 0; i < N; i++)
    {
        gets(structArr[i].nama);
        gets(structArr[i].NRP);
        gets(structArr[i].angkatan);
        gets(structArr[i].asal);
        gets(structArr[i].umur);
    }

    int command;
    while (scanf("%d", &command))
    {
        if (command == -1)
        {
            printf("===== DATA MAHASISWA =====\n");
            for (int i = 0; i < N; i++)
            {

                printData(structArr[i], i);
            }
            break;
        }
        else if (command == 1)
        {
            printf("===== HASIL PENCARIAN =====\n");
            char str[100];
            scanf(" %s", str);
            find(structArr, N, str);
        }
        else if (command == 2)
        {
            struct mahasiswa *ptr1;
            struct mahasiswa *ptr2;
            int index1;
            int index2;
            scanf("%d %d", &index1, &index2);
            ptr1 = &structArr[index1];
            ptr2 = &structArr[index2];
            swapUrut(ptr1, ptr2);
        }
        else if (command == 3)
        {
            char swapThis[10];
            scanf(" %s", swapThis);
            if (strcmp(swapThis, "nama") == 0)
            {
                int index1;
                int index2;
                scanf("%d %d", &index1, &index2);
                char *ptr1 = structArr[index1].nama;
                char *ptr2 = structArr[index2].nama;
                swapVal(ptr1, ptr2);
            }
            else if (strcmp(swapThis, "nrp") == 0)
            {
                int index1;
                int index2;
                scanf("%d %d", &index1, &index2);
                char *ptr1 = structArr[index1].NRP;
                char *ptr2 = structArr[index2].NRP;
                swapVal(ptr1, ptr2);
            }
            else if (strcmp(swapThis, "angkatan") == 0)
            {
                int index1;
                int index2;
                scanf("%d %d", &index1, &index2);
                char *ptr1 = structArr[index1].angkatan;
                char *ptr2 = structArr[index2].angkatan;
                swapVal(ptr1, ptr2);
            }
            else if (strcmp(swapThis, "umur") == 0)
            {
                int index1;
                int index2;
                scanf("%d %d", &index1, &index2);
                char *ptr1 = structArr[index1].umur;
                char *ptr2 = structArr[index2].umur;
                swapVal(ptr1, ptr2);
            }
            else if (strcmp(swapThis, "asal") == 0)
            {
                int index1;
                int index2;
                scanf("%d %d", &index1, &index2);
                char *ptr1 = structArr[index1].asal;
                char *ptr2 = structArr[index2].asal;
                swapVal(ptr1, ptr2);
            }
        }
    }
}