#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int target;

int solveA(int x, int target, int kedalaman)
{
    printf("%d;", x);
    if (target == kedalaman)
    {
        return x;
    }
    else
    {
        solveA(x * 2, target, kedalaman + 1);
        solveA(x * 2 + 1, target, kedalaman + 1);
    }
}

int solveB(int x, int target, int kedalaman)
{
    if (kedalaman == target + 1)
    {
        return x;
    }
    else
    {
        solveB(2 * x, target, kedalaman + 1);
        printf("%d;", x);
        solveB(2 * x + 1, target, kedalaman + 1);
    }
}

int solveC(int x, int target, int kedalaman)
{
    if (kedalaman == target + 1)
    {
        return x;
    }
    else
    {
        solveC(x * 2, target, kedalaman + 1);
        solveC(x * 2 + 1, target, kedalaman + 1);
        printf("%d;", x);
    }
}

int main()
{
    int N;
    char c;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %c", &target, &c);
        if (c == 'A')
        {
            printf("Menampilkan... berhasil! ");
            solveA(1, target, 0);
            printf("\n");
        }
        else if (c == 'B')
        {
            printf("Menampilkan... berhasil! ");
            solveB(1, target, 0);
            printf("\n");
        }
        else if (c == 'C')
        {
            printf("Menampilkan... berhasil! ");
            solveC(1, target, 0);
            printf("\n");
        }
    }
}