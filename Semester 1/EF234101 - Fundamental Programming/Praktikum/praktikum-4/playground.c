#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct laci
{
    char content[105];
};

int main()
{
    int a;
    scanf("%d", &a);
    while (a--)
    {
        int b;
        scanf("%d", &b);
        struct laci input[b];
        for (int i = 0; i < b; i++)
        {
            scanf(" %[^\n]", input[i].content);
        }

        int c;
        scanf("%d", &c);
        for (int i = 0; i < c; i++)
        {
            bool found = false;
            int saveIndex;
            char check[105];
            scanf(" %[^\n]", check);
            for (int j = 0; j < b;)
            {
                if (strcmp(check, input[j].content) == 0)
                {
                    found = true;
                    saveIndex = j;
                    break;
                }
                else
                {
                    j++;
                }
            }
            if (!found)
            {
                printf("Maaf, belum terlacak :^(\n");
            }
            else
            {
                printf("Ditemukan di laci ke-%d\n", saveIndex + 1);
            }
        }
    }
    return 0;
}