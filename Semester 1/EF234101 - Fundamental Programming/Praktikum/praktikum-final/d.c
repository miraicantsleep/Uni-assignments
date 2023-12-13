#include <stdio.h>
#include <math.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    int c, d, e, f;
    scanf("%d %d %d %d", &c, &d, &e, &f);

    int g, h;
    scanf("%d %d", &g, &h);

    // cek kalo udah di dalam
    if ((g <= (c + e / 2) && g >= (c - e / 2)) && (h <= d + (f / 2) && h >= d - (f / 2)))
    {
        printf("KAMU SUDAH SAMPAI");
    }
    else
    {
        double distance = sqrt(pow(g - c, 2) + pow(h - d, 2));
        printf("%.2f METER LAGI", distance);
    }

    return 0;
}
