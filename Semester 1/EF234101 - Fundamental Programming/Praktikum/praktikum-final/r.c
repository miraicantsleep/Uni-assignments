#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

char ans1[70];
char ans2[70];
int binary[64];
int counter = 0;
unsigned long long a, b;

void flushBinary()
{
    counter = 0;
    for (int i = 0; i < 64; i++)
    {
        binary[i] = 0;
    }
}
void decToBin(unsigned long long a)
{
    flushBinary();
    int i = 0;

    while (a > 0)
    {
        binary[i] = a % 2;
        a /= 2;
        i++;
        counter++;
    }
    // printf("\n");
    // for (int j = 0; j < i; j++)
    // {
    //     printf("%d", binary[j]);
    // }
    // printf("\n");
}

void solveA(unsigned long long a)
{
    decToBin(a);
    int i;
    for (i = 0; i < counter; i++)
    {
        char ch = binary[i] + '0';
        ans1[i] = ch;
    }
    ans1[i] = '\0';
    printf("\n");
    printf("%s", ans1);
    printf("\n");
}

void solveB(unsigned long long b)
{
    decToBin(b);
    int i;
    for (i = 0; i < counter; i++)
    {
        char ch = binary[i] + '0';
        ans2[i] = ch;
    }
    ans2[i] = '\0';
    printf("%s", ans2);
    printf("\n");
}

bool buzz = true;
void buzzOrWuzz()
{
    int length1 = strlen(ans1);
    int length2 = strlen(ans2);
    int pointer = 0;
    if (length1 < length2)
    {
        for (int i = 0; i < length1; i++)
        {
            if (ans1[i] != ans2[i] && ans1[i] == '1')
            {
                buzz = false;
                break;
            }
            else
            {
                continue;
            }
        }
        // printf("\n");
        if (buzz)
        {
            printf("Buzz");
        }
        else
        {
            printf("Wuzz");
        }
    }
    else if (length1 > length2)
    {
        for (int i = 0; i < length2; i++)
        {
            if (ans1[i] != ans2[i] && ans2[i] == '1')
            {
                buzz = false;
                break;
            }
            else
            {
                continue;
            }
        }
        // printf("\n");
        if (buzz)
        {
            printf("Buzz");
        }
        else
        {
            printf("Wuzz");
        }
    }
    else if (length1 == length2)
    {
        int lengthSame = length1;
        if (a > b)
        {
            for (int i = 0; i < lengthSame; i++)
            {
                if (ans1[i] != ans2[i] && ans2[i] == '1')
                {
                    buzz = false;
                    break;
                }
                else
                {
                    continue;
                }
            }
            // printf("\n");
            if (buzz)
            {
                printf("Buzz");
            }
            else
            {
                printf("Wuzz");
            }
        }
        else if (a < b)
        {
            for (int i = 0; i < lengthSame; i++)
            {
                if (ans1[i] != ans2[i] && ans1[i] == '1')
                {
                    buzz = false;
                    break;
                }
                else
                {
                    continue;
                }
            }
            // printf("\n");
            if (buzz)
            {
                printf("Buzz");
            }
            else
            {
                printf("Wuzz");
            }
        }
        else if (a == b)
        {
            printf("Buzz");
        }
    }
}

int main()
{

    scanf("%llu %llu", &a, &b);
    if (a % b == 0 || b % a == 0)
    {
        printf("Rizz");
        solveA(a);
        solveB(b);
        buzzOrWuzz();
    }
    else
    {
        printf("Not Rizz, but ");
        solveA(a);
        solveB(b);
        buzzOrWuzz();
        printf("!");
    }
    printf("\n");
}