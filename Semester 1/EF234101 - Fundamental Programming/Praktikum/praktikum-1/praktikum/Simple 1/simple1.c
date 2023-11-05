#define _USE_MATH_DEFINES // apcb
#include <stdio.h>
#include <math.h>

float radius = 0;
char input;
float jam = 0, menit = 0, detik = 0;

int main()
{
    scanf("%c %f %f:%f:%f", &input, &radius, &jam, &menit, &detik);

    if (jam >= 12)
    {
        jam -= 12;
    }

    if (input == 'L')
    {
        float degJarumPanjang = menit * 6;                   // convert jarum panjang/menit ke deg
        float degJarumPendek = jam * 30 + (menit / 60) * 30; // convert jarum pendek/jam ke deg
        float ansDeg = degJarumPendek - degJarumPanjang;     // dikurang agar mendapat jawaban

        if (ansDeg < 0)
        {
            ansDeg *= -1;
        }
        if (ansDeg > 180)
        {
            ansDeg = 360 - ansDeg;
        }
        

        float luasTerluas = ((360 - ansDeg) / 360) * M_PI * radius * radius; // dapatkan luas terluas dengan 360 - sudut terkecil lalu dikalikan rumus luas lingkaran
        printf("%.2f derajat %.2f m2\n", ansDeg, luasTerluas);
    }

    if (input == 'K')
    {
        float degJarumPanjang = menit * 6;                   // convert jarum panjang/menit ke deg
        float degJarumPendek = jam * 30 + (menit / 60) * 30; // convert jarum pendek/jam ke deg
        float ansDeg = degJarumPendek - degJarumPanjang;     // dikurang agar mendapat jawaban

        if (ansDeg < 0) // cek jika hasil operasi ansdeg negatif dan dikalikan -1
        {
            ansDeg *= -1;
        }
        if (ansDeg > 180) // cek jika ansdeg lebih besar dari 180, jika ansdeg lebih besar dari 180, ansdeg bukan sudut terkecil
        {
            ansDeg = 360 - ansDeg;
        }

        float kelilingTerluas = (((360 - ansDeg) / 360) * 2 * M_PI * radius) + (2 * radius); // cari keliling terluas, 360 - sudut terkecil agar dapat sudut terluas lalu dikalikan dengan rumus keliling lingkaran
        printf("%.2f derajat %.2f m\n", ansDeg, kelilingTerluas);
    }

    return 0;
}
