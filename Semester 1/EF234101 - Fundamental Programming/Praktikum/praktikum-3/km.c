#include <stdio.h>
// https://en.wikipedia.org/wiki/Modular_exponentiation

long long solve(int a, int b, int c)
{
    // int counter = 1;
    long long ans = a;
    if (b == 1)
    {
        return a % c;
    }
    else

        for (long long i = 1; i < b; i++)
        {
            ans = ans * a % c;
            // counter++;
        }
        // printf("%d\n", counter);
    return ans;
}

int main()
{
    int a, b, c;
    while (scanf("%d", &a) != EOF)
    {
        scanf("%d %d", &b, &c);
        printf("%lld\n", solve(a, b, c));
    }
}