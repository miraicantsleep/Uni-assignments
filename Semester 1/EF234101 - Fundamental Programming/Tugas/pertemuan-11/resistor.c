#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

char colorCode[10][10] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white"};
int search(char colorCode[][10], int size, char find[])
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(colorCode[i], find) == 0)
        {
            return i;
        }
    }
    return -1;
}

int saveIndex[3];
int calculate()
{
    int ans = saveIndex[0] * 10 + saveIndex[1];
    ans = (ans * (int)pow(10.0, saveIndex[2]) / 1000);
    if (ans > 0)
    {
        return ans;
    }
    else
    {
        return -1;
    }
}

int main()
{
    char ch = 'y';
    char band[3][10];
    while (ch == 'y')
    {
        printf("Enter the colors of the resistor's three bands, beginning with the band nearest the end. Type the colors in lowercase letters only, NO CAPS.\n");
        for (int i = 0; i < 3; i++)
        {
            printf("Band %d = > ", i + 1);
            scanf("%s", band[i]);
        }
        for (int i = 0; i < 3; i++)
        {
            saveIndex[i] = search(colorCode, 10, band[i]);
            if (saveIndex[i] == -1)
            {
                printf("Invalid color: %s\n", band[i]);
                break;
            }
        }
        if (calculate() > 0)
        {
            printf("Resistance value: %d kilo-ohms\n", calculate());
        }
        printf("Do you want to decode another resistor?\n=> ");
        scanf(" %c", &ch);
    }
}