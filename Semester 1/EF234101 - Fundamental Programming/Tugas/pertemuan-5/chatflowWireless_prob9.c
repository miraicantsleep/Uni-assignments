#include <stdio.h>

int main()
{
    int weekdayMin;
    int nightMin;
    int weekendMin;
    float totalPrice;

    printf("Input Weekday Minutes >> ");
    scanf("%d", &weekdayMin);
    printf("Input Night Minutes >> ");
    scanf("%d", &nightMin);
    printf("Input Weekend Minutes >> ");
    scanf("%d", &weekendMin);

    // count weekdays price
    int weekdayMinOverflow;
    float weekdayPrice = 3999;
    if (weekdayMin > 600)
    {
        weekdayMinOverflow = weekdayMin - 600;
        totalPrice = 39.99 + (weekdayMinOverflow * 40);
    }
    else
    {
        totalPrice = 3999;
    }
    // count average price per minute before tax
    int totalMin = weekdayMin + nightMin + weekendMin;
    float averagePrice = totalPrice / totalMin; // pakai weekday price karena night dan weekend nya free

    // count tax and total bill
    float tax = totalPrice * 0.0525;
    float totalBillbeforeTax = totalPrice;
    float totalBill = totalPrice + tax;
    float averagePrice_afterTax = totalBill / totalMin;

    printf("======================================================================\n");
    printf("| Weekday Minutes Spent                 |       %d Minutes\n", weekdayMin);
    printf("| Weekend Minutes Spent                 |       %d Minutes\n", weekendMin);
    printf("| Night Minutes Spent                   |       %d Minutes\n", nightMin);
    printf("| Total Minutes Spent                   |       %d Minutes\n", totalMin);
    printf("======================================================================\n");
    printf("| Flat Charge Rate                      |       39.99 dollars\n");
    printf("======================================================================\n");
    printf("| Total bill (before tax)               |       %.2f dollars\n", totalBillbeforeTax / 100);
    printf("| Tax                                   |       %.2f dollars\n", tax / 100);
    printf("| Total bill (after tax)                |       %.2f dollars", totalBill / 100);
}