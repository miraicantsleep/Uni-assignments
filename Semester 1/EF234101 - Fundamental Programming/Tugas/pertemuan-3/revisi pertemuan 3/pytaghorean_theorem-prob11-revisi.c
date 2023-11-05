#include <stdio.h>

int m, n;

int main()
{
    printf("Masukkan nilai m dan n : ");
    scanf("%d %d", &m, &n);

    // hitung side1, side2, hypotenuse
    int side1 = (m * m) - (n * n);
    int side2 = 2 * m * n;
    int hypotenuse = (m * m) + (n * n);

    // Cek jika m dan n adalah integer positif dan memastikan m > n
    if (m < 0 || n < 0 || m < n)
    {
        printf("Angka tidak memenuhi syarat");
    }
    else
    {
        printf("Side 1 : %d\nSide 2 : %d\nHypotenuse : %d", side1, side2, hypotenuse);
    }

    return 0;
}