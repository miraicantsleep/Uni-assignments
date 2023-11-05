#include <stdio.h>

int h1, m1, s1;
int jam, menit, detik;
int timezone;
int h2 = 0, m2 = 0, s2 = 0;
int temp_h2 = 0, temp_m2 = 0;

int main()
{
    scanf("%d:%d:%d", &h1, &m1, &s1);
    scanf("%d jam %d menit %d detik", &jam, &menit, &detik);
    scanf("%d", &timezone);

    s2 = s1 + detik;
    if (s2 >= 60)
    {
        s2 -= 60;
        temp_m2 += 1;
    }
    m2 = m1 + menit + temp_m2;
    if (m2 >= 60)
    {
        m2 -= 60;
        temp_h2 += 1;
    }

    h2 = h1 + jam + timezone + temp_h2;
    if (h2 >= 24)
    {
        h2 %= 24;
    }
    printf("Kuki akan tiba pada pukul %d:%d:%d waktu setempat", h2, m2, s2);
    return 0;
}
