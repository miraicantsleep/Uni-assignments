#include <stdio.h>

int main()
{
    int choice;
    printf("(1) First Free Service\n");
    printf("(2) Second Free Service\n");
    printf("Enter the free service number>> ");
    
    scanf("%d", &choice);
    int miles;
    switch (choice)
    {
    case 1:
        printf("Enter number of miles >>");
        scanf("%d", &miles);
        if (miles > 1500 && miles <= 3000)
        {
            printf("Vehicle must be serviced.");
        }

        break;
    case 2:
        printf("Enter number of miles >> ");
        scanf("%d", &miles);
        if (miles > 3001 && miles <= 4500)
        {
            printf("Vehicle must be serviced");
        }
    default:
        break;
    }
}