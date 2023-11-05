#include <stdio.h>
#include <string.h>


int main(){
    double a, b, c, d, e;
    scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);
    double total = a + b + c + d + e;
    double ans = total/5;
    printf("%.2lf", ans);
}