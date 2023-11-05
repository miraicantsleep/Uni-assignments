#include <stdio.h>

int main()
{
    long long arr[10001];
    long long arr2[1000];
    long long input;

    while (scanf("%lld", &input) == 1)
    {
        long long totalPower = 0;
        long long j = 0;
        long long inputFixed = input;
        while (inputFixed > 0)
        {
            arr2[j] = inputFixed;
            inputFixed /= 2;
            totalPower += arr2[j];
            j++;
        }

        printf("Suletta membutuhkan %lld power dengan path musuh yang perlu dikalahkan ", totalPower);
        for (long long k = j - 1; k >= 0; k--)
        {
            printf("%lld", arr2[k]);
            if (k != 0)
            {
                printf("-");
            }
        }
        printf("\n");
    }

    return 0;
}
