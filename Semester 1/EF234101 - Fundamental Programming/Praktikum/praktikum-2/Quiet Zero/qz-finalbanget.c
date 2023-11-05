#include <stdio.h>

int main()
{
    long long N;
    long long output[1001];
    scanf("%lld", &N);
    long long input[N]; // bentuk array dinamis sesuai inputan
    for (long long i = 0; i < N; i++)
    {
        scanf("%lld", &input[i]);
    }

    for (long long i = 0; i < N; i++)
    {
        // populate array output dengan pembagian input berulang oleh 2 dan tambahkan isi array
        long long counter = 0;
        long long totalPower = 0;
        long long inputFix = input[i];
        for (long long i = 0; inputFix > 0 ; i++)
        {
            output[counter] = inputFix;
            inputFix = inputFix / 2;
            totalPower += output[counter];
            counter++;
        }

        printf("Suletta membutuhkan %lld power dengan path musuh yang perlu dikalahkan 1", totalPower); // output dulu totalPower
        for (long long k = counter - 2; k >= 0; k--)
        {
            printf("-%lld", output[k]); // print angka
        }
        printf("\n"); // print newline setelah semua loop selesai
    }
}