#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct peti
{
    long long kunci;
    char content[20];
};

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    struct peti input[a];
    for (int i = 0; i < a; i++)
    {
        scanf("%lld %s", &input[i].kunci, input[i].content);
    }

    for (int i = 0; i < b; i++)
    {
        long long check;
        scanf("%lld", &check);
        bool found = false;
        int saveIndex;
        for (int j = 0; j < a;)
        {
            if (check == input[j].kunci)
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
            printf("========= Emangnya ada isinya? ============\n");
        }
        else
        {
            printf("%s\n", input[saveIndex].content);
        }
    }
}