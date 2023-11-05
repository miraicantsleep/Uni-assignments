#include <stdio.h>
#include <math.h>

char M, N;

int main(){
    scanf("%c %c", &M, &N);
    double ans = sqrt(M * N);
    printf("%.4lf", ans);

    return 0;
}