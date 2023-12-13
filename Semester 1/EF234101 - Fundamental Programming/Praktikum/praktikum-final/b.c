#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    int max = -999999999;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int *newArr = (int *)calloc(max + 2, sizeof(int));
    for (int i = 0; i < N; i++)
    {
        if (newArr[arr[i] + 1] != 0)
        {
            newArr[arr[i] + 1]--;
            newArr[arr[i]]++;
        }
        else
        {
            newArr[arr[i]]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < max + 2; i++)
    {
        ans += newArr[i];
    }
    printf("%d", ans);
    free(newArr);
}