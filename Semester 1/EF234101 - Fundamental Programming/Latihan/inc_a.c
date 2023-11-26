#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct participants
{
    char teamName[100];
    char instituteName[100];
};

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    struct participants input[a];
    for (int i = 0; i < a; i++)
    {
        scanf("%s %s", input[i].teamName, input[i].instituteName);
    }

    char except[101][100];
    strcpy(except[0], input[0].instituteName); // copy institut pertama ke exception
    int counter = 1;
    for (int i = 1; i <= b - 1;)
    {
        if (strcmp(except[i], except[i - 1]) == 0)
        {
            i++;
        }
        else
        {
            strcpy(except[i], input[i].instituteName);
            counter++;
            i++;
        }
    }

    int tiket = 0;
    char jawaban[101][101];
    for (int i = b; i < a; i++)
    {
        int j = 0;
        bool alreadyExist = false;
        while (j < counter)
        {
            if (strcmp(input[i].instituteName, except[j]) == 0)
            {
                alreadyExist = true;
                break;
            }
            else
            {
                j++;
            }
        }

        if (!alreadyExist && tiket < c)
        {
            // printf("%s\n", input[i].teamName);
            strcpy(jawaban[tiket], input[i].teamName);
            tiket++;
            strcpy(except[counter], input[i].instituteName);
            counter++;
        }
    }
    if (tiket == 0)
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n", tiket);
        for (int i = 0; i < tiket; i++)
        {
            printf("%s\n", jawaban[i]);
        }
    }
}