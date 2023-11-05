#include <stdio.h> // bjir ini susah amat dah

float whiteBreadTime(char method, char breadSize)
{
    int primaryKneading = 15;
    int primaryRising = 60;
    int secondaryKneading = 18;
    int secondaryRising = 20;
    float loafShaping = 2.0 / 60;
    int finalRising = 75;
    int baking = 45;
    int cooling = 30;
    if (method == 'A')
    {
        if (breadSize == 'N')
        {
            float totalTime = primaryKneading + primaryRising + secondaryKneading + secondaryRising + loafShaping + finalRising + baking + cooling;
            return totalTime;
        }
        else if (breadSize == 'D')
        {
            float bakingTimeDouble = baking * 1.5;
            float totalTime = primaryKneading + primaryRising + secondaryKneading + secondaryRising + loafShaping + finalRising + bakingTimeDouble + cooling;
            return totalTime;
        }
    }
    else if (method == 'M')
    {
        float totalTime = primaryKneading + primaryRising + secondaryKneading + secondaryRising + loafShaping;
        printf("Remove the dough for manual baking.");
        return totalTime;
    }

    return -1;
}

float sweetBreadTime(char method, char breadSize)
{
    int primaryKneading = 20;
    int primaryRising = 60;
    int secondaryKneading = 33;
    int secondaryRising = 30;
    float loafShaping = 2.0 / 60;
    int finalRising = 75;
    int baking = 35;
    int cooling = 30;
    if (method == 'A')
    {
        if (breadSize == 'N')
        {
            float totalTime = primaryKneading + primaryRising + secondaryKneading + secondaryRising + loafShaping + finalRising + baking + cooling;
            return totalTime;
        }
        else if (breadSize == 'D')
        {
            float bakingTimeDouble = 35 * 1.5;
            float totalTime = primaryKneading + primaryRising + secondaryKneading + secondaryRising + loafShaping + finalRising + bakingTimeDouble + cooling;
            return totalTime;
        }
    }
    else if (method == 'M')
    {
        float totalTime = primaryKneading + primaryRising + secondaryKneading + secondaryRising + loafShaping;
        printf("Remove the dough for manual baking.");
        return totalTime;
    }
    return -1;
}

int main()
{
    char breadType;
    char bakingMethod;
    char breadSize;

    printf("Input bread type (W for White, S for Sweet) >> ");
    scanf(" %c", &breadType);
    printf("Input bread size (N for Normal, D for Double) >> ");
    scanf(" %c", &breadSize);
    printf("Input baking method (A for Automatic, M for Manual >> ");
    scanf(" %c", &bakingMethod);

    float totalTime;
    if (breadType == 'W')
    {
        totalTime = whiteBreadTime(bakingMethod, breadSize);
    }
    else if (breadType == 'S')
    {
        totalTime = sweetBreadTime(bakingMethod, breadSize);
    }
    else
    {
        printf("Bread Type Invalid.");
    }

    if (totalTime != -1)
    {
        printf("Total time required to make the bread is : %.2f minutes", totalTime);
    }

    return 0;
}