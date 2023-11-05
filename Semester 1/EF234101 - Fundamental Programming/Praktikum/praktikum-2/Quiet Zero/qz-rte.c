#include <stdio.h>

int main()
{
    long long N;
    long long input[1001];
    long long output[1001];
    scanf("%lld", &N);
    for (long long i = 0; i < N; i++)
    {
        scanf("%lld", &input[i]);
    }

    for (long long i = 0; i < N; i++)
    {
        // populate array output dengan pembagian input berulang oleh 2 dan tambahkan isi array
        long long j = 0;
        long long totalPower = 0;
        long long inputFix = input[i];
        while (inputFix > 0)
        {
            output[j] = inputFix;
            inputFix = inputFix / 2;
            totalPower += output[j];
            j++;
        }
        printf("Suletta membutuhkan %lld power dengan path musuh yang perlu dikalahkan 1", totalPower); // output dulu totalPower
        for (long long k = j - 2; k >= 0; k--)
        {
            printf("-%lld", output[k]); // print angka
        }
        printf("\n"); // print newline setelah semua loop selesai
    }
}