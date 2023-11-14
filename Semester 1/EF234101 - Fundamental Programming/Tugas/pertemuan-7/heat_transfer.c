#include <stdio.h>

void calc_A(double m, double *area, double del_t, double k, double H)
{
    *area = (H * m) / (k * del_t);
}

void calc_k(double m, double area, double del_t, double *k, double H)
{
    *k = (H * m) / (area * del_t);
}

void calc_H(double m, double area, double del_t, double k, double *heat_transfer)
{
    *heat_transfer = (k * area * del_t) / m;
}

void calc_X(double *m, double area, double del_t, double k, double H)
{
    *m = (k * area * del_t) / H;
}

void calc_T2(double m, double area, double t1, double *t2, double k, double H)
{
    *t2 = ((H * m) / (k * area)) + t1;
}

void calc_T1(double m, double area, double *t1, double t2, double k, double H)
{
    *t1 = t2 - ((H * m) / (k * area));
}

void main()
{
    double H, k, A, T1, T2, X;
    int input1, input2, input3, input4, input5, input6;
    char ch;
    printf("\nRespond to the prompts with the data known. For the unknown quantity, enter a question mark (?).");

    printf("\nRate of heat transfer (watts) >> ");
    input1 = scanf(" %lf", &H);
    if(input1 == 0)
        scanf("%c", &ch);

    printf("\nCoefficient of thermal conductivity (W/m-K) >> ");
    input2 = scanf(" %lf", &k);
    if(input2 == 0)
        scanf("%c", &ch);

    printf("\nCross-sectional area of conductor (m^2) >> ");
    input3 = scanf(" %lf", &A);
    if(input3 == 0)
        scanf("%c", &ch);

    printf("\nTemperature on one side (K) >> ");
    input4 = scanf(" %lf", &T2);
    if(input4 == 0)
        scanf("%c", &ch);

    printf("\nTemperature on other side (K) >> ");
    input5 = scanf(" %lf", &T1);
    if(input5 == 0)
        scanf("%c", &ch);

    printf("\nThickness of conductor (m) >> ");
    input6 = scanf(" %lf", &X);
    if(input6 == 0)
        scanf("%c", &ch);

    if(input1 == 0)
        calc_H(X, A, (T2 - T1), k, &H);
    else if(input2 == 0)
        calc_k(X, A, (T2 - T1), &k, H);
    else if(input3 == 0)
        calc_A(X, &A, (T2 - T1), k, H);
    else if(input4 == 0)
        calc_T2(X, A, T1, &T2, k, H);
    else if(input5 == 0)
        calc_T1(X, A, &T1, T2, k, H);
    else if(input6 == 0)
        calc_X(&X, A, (T2 - T1), k, H);

    printf("\n\n%5ckA (T2 - T1)", ' ');
    printf("\nH = ----------------");
    printf("\n%10cX", ' ');

    if(input1 == 0)
        printf("\nRate of heat transfer is %.3f W.", H);
    else if(input2 == 0)
        printf("\nCoefficient of thermal conductivity is %.3f W/m-K.", k);
    else if(input3 == 0)
        printf("\nCross-sectional area of conductor is %.3f m^2.", A);
    else if(input4 == 0)
        printf("\nTemperature on the other side is %.0f K.", T2);
    else if(input5 == 0)
        printf("\nTemperature on the other side is %.0f K.", T1);
    else if(input6 == 0)
        printf("\nThickness of conductor is %.4f m.", X);

    printf("\nH = %.3f W.", H);
    printf("\nk = %.3f W/m-K.", k);
    printf("\nA = %.3f m^2.", A);
    printf("\nT2 = %.0f K.", T2);
    printf("\nT1 = %.0f K.", T1);
    printf("\nm = %.4f m.", X);
}