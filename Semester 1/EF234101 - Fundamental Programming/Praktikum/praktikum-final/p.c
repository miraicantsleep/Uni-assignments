#include <stdio.h>

int solve(int arr[], int size)
{
    if (size == 1)
    {
        return arr[0];
    }
    else
    {
        int tempArr[size - 1];
        for (int i = 0; i < size - 1; i++)
        {
            tempArr[i] = arr[i + 1] - arr[i];
        }
        return arr[size - 1] + solve(tempArr, size - 1);
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    int ans = solve(arr, N);
    printf("%d", ans);

    return 0;
}