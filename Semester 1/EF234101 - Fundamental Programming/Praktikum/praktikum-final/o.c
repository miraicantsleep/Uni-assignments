#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

long long fpb(long long a, long long b)
{
    if (b == 0)
    {
        return a;
    }
    return fpb(b, a % b);
}

int main()
{
    long long a, b;
    scanf("%lld %lld", &a, &b);
    long long ans = fpb(a, b);
    int digit = 0;
    while (ans != 0)
    {
        ans /= 10;
        digit++;
    }
    if (digit % 2 == 0)
    {
        printf("Yey brankas berhasil dibuka :D");
    }
    else
    {
        printf("Yah gagal :(");
    }
}