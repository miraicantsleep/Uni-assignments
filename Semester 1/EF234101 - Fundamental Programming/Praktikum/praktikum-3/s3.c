#include <stdio.h>
#include <string.h>

char arr[1001][1001];
int N;
int selisihX;
int selisihY;

int assignPos()
{
    int xPosS;
    int yPosS;
    int xPosF;
    int yPosF;
    int Sfound = 0;
    int Ffound = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%s", arr[i]);
    }

    for (int i = 0; i < N; i++)
    {
        if (Sfound == 1 && Ffound == 1)
        {
            break;
        }
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 'S')
            {
                xPosS = i;
                yPosS = j;
                Sfound = 1;
            }
            else if (arr[i][j] == 'F')
            {
                xPosF = i;
                yPosF = j;
                Ffound = 1;
            }
            if (Sfound == 1 && Ffound == 1)
            {
                break;
            }
        }
    }

    if (xPosF < xPosS || yPosF < yPosS)
    {
        printf("ERROR BANG!\n");
        return -1;
    }
    else
    {
        selisihX = xPosF - xPosS;
        selisihY = yPosF - yPosS;
        return 0;
    }
}

int calculate(int x, int y)
{
    return (x * y) + 1;
}

int main()
{
    scanf("%d ", &N);
    if (assignPos() != -1)
    {
        int ans = calculate(selisihX, selisihY);
        printf("%d\n", ans);
    }
}