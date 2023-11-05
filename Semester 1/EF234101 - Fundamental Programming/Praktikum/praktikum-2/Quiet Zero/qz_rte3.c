#include <stdio.h>

int main()
{
    int N;
    long long arr[N];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &arr[i]);
        long long inputFix = arr[i];
        long long totalPower = 0;
        for (long long j = 0; inputFix > 0; j++) // masukkan hasil perhitungan inputFix/2 ke arr[j]
        {
            arr[j] = inputFix;
            totalPower += inputFix;
            inputFix /= 2;
        }
    }
}