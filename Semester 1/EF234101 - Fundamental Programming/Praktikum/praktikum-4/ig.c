#include <stdio.h>
#include <string.h>

int solveDet(int a, int b, int c, int d)
{
    return (a * d) - (b * c);
}

void swap(int *var1, int *var2)
{
    int temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}

struct penduduk
{
    char nama[20];
    int det;
};

int main()
{
    int N;
    scanf("%d", &N);
    getchar();
    struct penduduk input[N];
    for (int i = 0; i < N; i++)
    {
        int a, b, c, d;
        scanf("%s", input[i].nama);
        getchar();
        scanf("%d %d %d %d", &a, &b, &c, &d);
        input[i].det = solveDet(a, b, c, d);
    }

    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        char query[8];
        char name1[20];
        char name2[20];

        scanf("%s", query);
        if (strcmp(query, "swap") == 0)
        {
            scanf("%s %s", &name1, &name2);
            int *ptr1;
            int *ptr2;
            for (int j = 0; j < N; j++)
            {
                if (strcmp(input[j].nama, name1) == 0)
                {
                    ptr1 = &input[j].det;
                    break;
                }
                else
                {
                    continue;
                }
            }
            for (int j = 0; j < N; j++)
            {
                if (strcmp(input[j].nama, name2) == 0)
                {
                    ptr2 = &input[j].det;
                    break;
                }
                else
                {
                    continue;
                }
            }
            swap(ptr1, ptr2);
        }
        else if (strcmp(query, "ans") == 0)
        {
            scanf("%s", name1);
            for (int i = 0; i < N; i++)
            {
                if (strcmp(input[i].nama, name1) == 0)
                {
                    printf("%s => %d\n", input[i].nama, input[i].det);
                }
                else
                {
                    continue;
                }
            }
        }
    }
}