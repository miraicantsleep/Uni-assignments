#include <stdio.h>
#include <math.h>
double pendapatan(int);
void prediksi(double);
double round_number(double);

void utama()
{
    int t;
    double R, triliun = pow(10, 12);
    prediksi(triliun);
}

double pendapatan(int t)
{
    t -= 1984;
    double R = 203.265 * pow(1.071, t);
    return R;
}

void prediksi(double R)
{
    int t = 1984;
    FILE *keluaran = fopen("table.txt", "w");
    
    fprintf(keluaran, "Year %5c Revenue", ' ');
    
    while(pendapatan(t) < R)
    {
        fprintf(keluaran, "\n%d %5c %lf", t, ' ', round_number(pendapatan(t)));
        t++;
    }
    fclose(keluaran);
}

double round_number(double num)
{
    int digit = 3;
    num = (long int)((num * pow(10, digit)) + 0.5) * 0.001;
    
    return num;
}
