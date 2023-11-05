#include <stdio.h>

long long a, b, c, d, e;

int main(){
    scanf("%lli %lli %lli %lli %lli", &a ,&b, &c, &d, &e);
    long long ans = a + b + c + d + e;
    printf("%lli", ans);

    return 0;

}