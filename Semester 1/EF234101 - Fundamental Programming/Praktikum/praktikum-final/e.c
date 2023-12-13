#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

void solve(int N, int matrix[N][N])
{
    int temp[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            temp[N - 1 - j][i] = matrix[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = temp[i][j];
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int size, rotate;
        scanf("%d %d", &size, &rotate);
        int row = size;
        int column = size;
        int matrix[row][column];
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                scanf("%d", &matrix[i][j]);
            }
        }

        for (int i = 0; i < rotate; i++)
        {
            solve(size, matrix);
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }
}