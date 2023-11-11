#include <stdio.h>
char arr[1001][1001];
int val[1001][1001];

int N;

int startPosX;
int startPosY;
int finPosX;
int finPosY;

void assignPos()
{
    int startFound = 0;
    int finFound = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%s", arr[i]);
    }

    for (int i = 0; i < N; i++)
    {
        if (startFound == 1 && finFound == 1)
        {
            break;
        }

        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 'S')
            {
                startPosX = i;
                startPosY = j;
                startFound = 1;
            }
            else if (arr[i][j] == 'F')
            {
                finPosX = i;
                finPosY = j;
                finFound = 1;
            }
            if (startFound == 1 && finFound == 1)
            {
                break;
            }
        }
    }
}

void assignVal(int size)
{
    int init = 0;
    int increment = 1;
    int rowVal, place;
    for (int i = 0; i < N; i++)
    {
        init += increment;
        rowVal = increment;
        place = init;
        for (int j = 0; j < N; j++)
        {
            val[i][j] = place;
            place = place + increment + j;
        }
        increment++;
    }
}

int realMap[1001][1001];
void posToVal()
{
}

int main()
{
    scanf("%d", &N);
    assignPos();
    assignVal(N);
    if (startPosX > finPosX || startPosY > finPosY)
    {
        printf("ERROR BANG!\n");
    }
    else
    {
        assignVal(N);
    }
}