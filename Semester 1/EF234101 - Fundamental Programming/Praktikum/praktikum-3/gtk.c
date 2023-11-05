#include <stdio.h>

int arr[1001];
int memo[1001] = {0};

long long solveFibMod(int N)
{
    if (N <= 2)
    {
        return N;
    }

    if (memo[N] == 0)
    {
        arr[N] = solveFibMod(N - 1) + solveFibMod(N - 2) + solveFibMod(N - 3);
        arr[N] %= 100;
        memo[N] = arr[N];
        return memo[N];
    }
    else
    {
        return memo[N];
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    solveFibMod(N + 1);
    for (int i = N; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}