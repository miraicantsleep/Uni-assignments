#include <stdio.h>

void solve(long long a, long long b, long long c, long long d, long long e)
{
    b = (a % b);
    d *= c;
    e = (b + d) % e;
    printf("%lld\n", e);
}
int main()
{
    long long a, b, c, d, e;
    long long N;
    scanf("%lld", &N);
    for (long long i = 0; i < N; i++)
    {
        scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &e);
        solve(a, b, c, d, e);
    }
}