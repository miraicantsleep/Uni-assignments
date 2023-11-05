#include <stdio.h>
#include <string.h>

int main()
{
    int N;
    int bisaKapan[10];
    char inputHari[10];
    char hari[7][10] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu", "Minggu"};
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &bisaKapan[i]);
    }

    // cari kpk
    int kpk = bisaKapan[0];
    for (int i = 1; i < N; i++)
    {
        if (kpk < bisaKapan[i])
        {
            int temp1 = kpk;
            int temp2 = bisaKapan[i];
            kpk = temp2; 
            bisaKapan[i] = temp1;
        }
        int temp = kpk;
        while (kpk % bisaKapan[i] != 0)
        {
            kpk = kpk + temp;
        }
    }

    // compare str input dengan isi array hari supaya dapet index
    scanf("%s", inputHari);
    int indexOfHariInput;
    for (int i = 0; i < 7; i++)
    {
        if (strcmp(inputHari, hari[i]) == 0)
        {
            indexOfHariInput = i;
            break;
        }
    }

    int IndexofShiftHari = (indexOfHariInput + kpk) % 7;
    printf("%s", hari[IndexofShiftHari]);
}