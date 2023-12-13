#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

void solve(unsigned long long a, unsigned long long b)
{
    bool rizz = false;
    if (a % b == 0 || b % a == 0)
    {
        rizz = true;
    }

    bool buzz = false;
    if ((a | b) == a || (a | b) == b)
    {
        buzz = true;
    }

    bool wuzz = false;
    if ((a & b) == 0 || (b & a) == 0)
    {
        wuzz = true;
    }

    if (rizz)
    {
        printf("Rizz");
        if (buzz)
        {
            printf("Buzz");
        }
        if (wuzz)
        {
            printf("Wuzz");
        }
    }
    else if (!rizz)
    {
        printf("Not Rizz");
        if (buzz)
        {
            printf(", but Buzz!");
        }
        if (wuzz)
        {
            printf(", but Wuzz!");
        }
        return;
    }
}

int main()
{
    unsigned long long a, b;
    scanf("%llu %llu", &a, &b);
    solve(a, b);
}