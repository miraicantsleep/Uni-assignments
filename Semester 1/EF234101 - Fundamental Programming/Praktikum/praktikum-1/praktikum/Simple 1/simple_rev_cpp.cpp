#include <bits/stdc++.h>
using namespace std;

float radius = 0;
char input;
char colon = ':';
float jam = 0, menit = 0, detik = 0;

int main()
{

    cin >> input >> radius >> jam >> colon >> menit >> colon >> detik;
    if (jam >= 12)
    {
        jam -= 12;
    }

    if (input == 'L')
    {
        float degJarumPanjang = menit * 6;
        float degJarumPendek = jam * 30 + (menit / 60) * 30;
        float ansDeg = degJarumPendek - degJarumPanjang;

        float luas = (ansDeg / 360) * M_PI * radius * radius;

        if (ansDeg < 0)
        {
            ansDeg *= -1;
        }
        if (ansDeg > 180)
        {
            ansDeg = 360 - ansDeg;
        }
        cout << fixed << setprecision(2) << ansDeg << " derajat " << luas << " m2" << endl;
    }
    if (input == 'K')
    {
        float degJarumPanjang = menit * 6;
        float degJarumPendek = (jam * 30) + (menit / 60) * 30;
        float ansDeg = degJarumPendek - degJarumPanjang;

        if (ansDeg < 0)
        {
            ansDeg *= -1;
        }
        if (ansDeg > 180)
        {
            ansDeg = 360 - ansDeg;
        }

        float keliling = (ansDeg/360) * 2 * M_PI * radius;
        cout << fixed << setprecision(2) << ansDeg << " derajat " << keliling << " m" << endl;
    }
}