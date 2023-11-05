#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int N;
    scanf("%d", &N);
    if (N >= 0 && N <= 40)
    {
        printf("E");
    }
    else if (N >= 41 && N <= 55)
    {
        printf("D");
    }
    else if (N >= 56 && N <= 60)
    {
        printf("C");
    }
    else if (N >= 61 && N <= 65)
    {
        printf("BC");
    }
    else if (N >= 66 && N <= 75)
    {
        printf("B");
    }
    else if (N >= 76 && N <= 85)
    {
        printf("AB");
    }
    else if (N >= 86 && N <= 100)
    {
        printf("A");
    }
    return 0;
}