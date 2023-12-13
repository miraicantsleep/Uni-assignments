#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(char arg1[], char arg2[])
{
    char temp[100];
    strcpy(temp, arg1);
    strcpy(arg1, arg2);
    strcpy(arg2, temp);
}

int main()
{
    int N;
    scanf("%d", &N);
    char item[10001][15];
    for (int i = 0; i < N; i++)
    {
        scanf("%s", item[i]);
    }

    int what;
    scanf("%d", &what);
    for (int i = 0; i < what; i++)
    {
        char arg1[15];
        char arg2[15];
        int arg1Index = -1;
        int arg2Index = -1;
        scanf("%s %s", arg1, arg2);
        for (int j = 0; j < N; j++)
        {
            if (strcmp(arg1, item[j]) == 0)
            {
                arg1Index = j;
                break;
            }
        }
        for (int j = 0; j < N; j++)
        {
            if (strcmp(arg2, item[j]) == 0)
            {
                arg2Index = j;
                break;
            }
        }
        swap(item[arg1Index], item[arg2Index]);
    }
    for (int i = 0; i < N; i++)
    {
        printf("%s\n", item[i]);
    }
}