    #include <stdio.h>

double x1, y1, x2, y2;

// Hitung gradien dari input
double gradientA()
{
    return (y2 - y1) / (x2 - x1); // akan error jika x2 - x1 = 0
}

// Hitung koordinat titik tengah y
double yMid()
{
    return (y2 + y1) / 2;
}

// Hitung koordinat titik tengah x
double xMid()
{
    return (x2 + x1) / 2;
}

// Hitung kemiringan garis yang tegak lurus
double gradientB()
{
    return -1 / gradientA(); // akan error jika gradientA() = 0
}

/*
Diketahui dalam soal bahwa y intercept = y mid - (m . x mid)
bisa disimpulkan b = yMid - (gradientB . xMid)
*/
double b()
{
    return yMid() - (gradientB() * xMid());
}

int main()
{
    printf("Masukkan x1, y1 | Format input : (x1 y1)\nInput : ");
    scanf("%lf %lf", &x1, &y1);

    printf("Masukkan x2, y2 | Format input : (x2 y2)\nInput : ");
    scanf("%lf %lf", &x2, &y2);

    //    printf("Gradien dari titik awal adalah : %.2lf\n\n", gradientA());

    //    printf("Koordinat titik tengah adalah : (%.2lf, %.2lf)\n\n", xMid(), yMid());

    //    printf("Gradien dari garis yang tegak lurus adalah : %.2lf\n\n", gradientB());

    //    printf("Persamaan dari garis yang tegak lurus adalah : y = %.2lfx + %.2lf", gradientB(), b());

    printf("y = %.2lfx + %.2lf", gradientB(), b());

    return 0;
}