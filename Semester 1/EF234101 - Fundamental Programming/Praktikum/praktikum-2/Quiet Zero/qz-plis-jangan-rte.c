#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    long long arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &arr[i]);
    }

    for (int i = 0; i < N; i++)
    {
        long long totalPower = 0;
        long long inputFix = arr[i];
        long long counterBuatPrint = 0;
        long long output[1000];
        for (int j = inputFix; j >= 1; j /= 2)
        {
            totalPower += j;
            output[counterBuatPrint] = j;
            counterBuatPrint++;
        }
        printf("Suletta membutuhkan %lld power dengan path musuh yang perlu dikalahkan 1", totalPower);

        for (long long j = counterBuatPrint - 2; j >= 0; j--)
        {
            printf("-%lld", output[j]);
        }
        printf("\n");
    }
}
/*
Kodingan langit yang akan menjadi sebuah takdir nilai ku,
menjadikan hamparan bahwa saksi ini, detik ini,
menurut test case domjudge yang akan memberikan ac menjadi nyata.
Aku sudah mempersembahkan solver ku untuk kamu, probset.
*/