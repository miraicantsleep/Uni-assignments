#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

int ans[8];

void initAnsZero()
{
    for (int i = 0; i < 8; i++)
    {
        ans[i] = 0; // init all zero
    }
}

void charToBin(char message[], int length)
{
    for (int i = 0; i < length; i++)
    {
        initAnsZero(); // init
        int ch = message[i];
        for (int j = 7; j >= 0; j--)
        {
            ans[j] = ch % 2;
            ch /= 2;
        }

        for (int j = 0; j < 8; j++)
        {
            printf("%d", ans[j]);
        }
    }
}

void binToChar(char message[], int length)
{
    for (int i = 0; i < length; i += 8)
    {
        char binaryChunk[9];
        strncpy(binaryChunk, message + i, 8);
        binaryChunk[8] = '\0';

        int decimalValue = strtol(binaryChunk, NULL, 2);
        printf("%c", decimalValue);
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    getchar();
    char message[8005];
    int length = 0;
    while (scanf("%c", &message[length]) != EOF)
    {
        length++;
    }
    if (N == 1)
    {
        charToBin(message, length);
    }
    else if (N == -1)
    {
        binToChar(message, length);
    }

    return 0;
}
