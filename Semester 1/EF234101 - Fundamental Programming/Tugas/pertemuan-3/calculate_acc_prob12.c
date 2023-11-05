#include <stdio.h>

int distance, takeOffSpeed;

/*

Hitung t dari s = 1/2 . a . t^2
karena v = a.t bisa disimpulkan s = 1/2.v.t
untuk mendapatkan t balik rumus t = s/(1/2 . v)

*/

// m/s = (km/h * 1000)/3600
double convertedSpeed()
{
    return (takeOffSpeed * 1000) / 3600;
}

double calculateTime()
{
    return distance / (0.5 * convertedSpeed());
}

// a = v / t
double calculateAccel()
{
    double time = calculateTime();
    return convertedSpeed() / time;
}

int main()
{
    printf("Enter Take Off Speed (km/h) : ");
    scanf("%d", &takeOffSpeed);

    printf("Enter Distance (meters) : ");
    scanf("%d", &distance);

    double time = calculateTime();
    double accel = calculateAccel();

    printf("\nTime to takeoff speed is : %.2lf seconds", time);
    printf("\nAcceleration is : %.2lf m/s^2\n", accel);

    return 0;
}