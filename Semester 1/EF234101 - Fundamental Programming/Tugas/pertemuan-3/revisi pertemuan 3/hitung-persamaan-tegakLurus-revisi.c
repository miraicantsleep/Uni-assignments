#include <stdio.h>

double x1, y1, x2, y2;

int main(){
    printf("Masukkan x1, y1 | Format input : (x1 y1)\nInput : ");
    scanf("%lf %lf", &x1, &y1);

    printf("Masukkan x2, y2 | Format input : (x2 y2)\nInput : ");
    scanf("%lf %lf", &x2, &y2);

    // Hitung gradien input
    double gradientA = (y2 - y1) / (x2 - x1); // Program akan fail saat x2 - x1 = 0
    // Hitung titik tengah y
    double yMid = (y2 + y1) / 2;
    // Hitung titik tengah x
    double xMid = (x2 + x1) / 2;
    // Hitung gradien garis yang dicari
    double gradientB = -1 / gradientA; // Program akan fail saat gradientA = 0
    /*
    Diketahui dalam soal bahwa y intercept = y mid - (m . x mid)
    bisa disimpulkan b = yMid - (gradientB . xMid)
    */
   double b = yMid - (gradientB * xMid);

   printf("y = %.2lfx + %.2lf", gradientB, b);

}