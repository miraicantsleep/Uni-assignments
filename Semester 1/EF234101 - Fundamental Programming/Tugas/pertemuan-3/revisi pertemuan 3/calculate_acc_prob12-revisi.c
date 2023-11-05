#include <stdio.h>

int distance, takeOffSpeed;

int main()
{
    printf("Enter Take Off Speed (km/h) : ");
    scanf("%d", &takeOffSpeed);
    double convertedSpeed = (takeOffSpeed * 1000) / 3600; // konversi km/h jadi m/s

    printf("Enter Distance (meters) : ");
    scanf("%d", &distance);

    // Masuk fungsi
    /*
    Hitung t dari s = 1/2 . a . t^2
    karena v = a.t bisa disimpulkan s = 1/2.v.t
    untuk mendapatkan t balik rumus t = s/(1/2 . v)
    */
    double timeToTakeoff = distance / (0.5 * convertedSpeed);
    double accel = convertedSpeed / timeToTakeoff;

    printf("\nTime to takeoff speed is : %.2lf seconds", timeToTakeoff);
    printf("\nAcceleration is : %.2lf m/s^2\n", accel);
}