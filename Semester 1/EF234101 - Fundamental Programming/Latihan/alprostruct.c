#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct nilaiUN
{
    char nama[100];
    int nilaiMat;
    int nilaiIPA;
    int nilaiInd;
    int nilaiEng;
};

void printNilai(struct nilaiUN data)
{
    printf("Nilai %s\n", data.nama);
    printf("Matematika : %d\n", data.nilaiMat);
    printf("IPA : %d\n", data.nilaiIPA);
    printf("Bahasa Indonesia : %d\n", data.nilaiInd);
    printf("Bahasa Inggris : %d\n", data.nilaiEng);
}

int main()
{
    int N;
    scanf("%d", &N);
    struct nilaiUN dataInput[N];
    getchar();
    for (int i = 0; i < N; i++)
    {
        fgets(dataInput[i].nama, sizeof(dataInput[i].nama), stdin);
        dataInput[i].nama[strlen(dataInput[i].nama) - 1] = '\0';
        scanf("%d", &dataInput[i].nilaiMat);
        scanf("%d", &dataInput[i].nilaiIPA);
        scanf("%d", &dataInput[i].nilaiInd);
        scanf("%d", &dataInput[i].nilaiEng);
        getchar();
    }

    int M;
    char inputNama[100];
    scanf("%d", &M);
    getchar();
    for (int i = 0; i < M; i++)
    {
        fgets(inputNama, sizeof(inputNama), stdin);
        inputNama[strlen(inputNama) - 1] = '\0';
        bool found = false;
        for (int j = 0; j < N; j++)
        {

            if (strcmp(inputNama, dataInput[j].nama) == 0)
            {
                printNilai(dataInput[j]);
                found = true;
                break;
            }
        }

        if (!found)
        {
            printf("Nilai %s tidak ditemukan\n", inputNama);
        }
    }
}