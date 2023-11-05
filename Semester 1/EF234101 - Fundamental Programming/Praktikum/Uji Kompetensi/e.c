#include <stdio.h>

int main()
{
    int N;
    int limit;
    int find;
    int arr[1001];
    scanf("%d %d", &N, &limit);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    // to new arr
    int newArr[1001];
    for (int i = 0; i < N; i++)
    {
        int index = arr[i];
        newArr[index]++;
    }

    scanf("%d", &find);
    printf("%d", newArr[find]);
}