#include <stdio.h>

int main()
{
    int arr[3];
    int max = -99999999;
    int min = 999999999;

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    int mid;
    for (int i = 0; i < 3; i++)
    {
        if (arr[i] != max && arr[i] != min)
        {
            mid = arr[i];
            break;
        }
    }
    
    int maxSqrd = max * max;
    int minSqrd = min * min;
    int midSqrd = mid * mid;
    // count pythagoras
    if (maxSqrd == minSqrd + midSqrd)
    {
        printf("%d %d %d", min, mid, max);
    }
    else
    {
        printf("Bukan Tripel Pythagoras.");
    }
    
}