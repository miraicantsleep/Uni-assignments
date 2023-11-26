#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    int targetAngka;
    scanf("%d", &targetAngka);
    int index1 = 0;
    int index2 = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i] + arr[j] != targetAngka)
            {
                continue;
            }
            else
            {
                index1 = j;
                index2 = i;
                break;
            }
        }
    }
    printf("%d & %d", index1, index2);
}