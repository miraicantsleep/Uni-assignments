#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct item
{
    int id;
    char nama[100];
    int harga;
    int kualitas;
};

void printData(struct item data[], int index)
{
    printf("%d %s %d %d\n", data[index].id, data[index].nama, data[index].harga, data[index].kualitas);
}

void lookForPrice(struct item data[], int dataSize)
{
    int lowestPrice = 100001;
    int lowestPriceIndex = 0;
    for (int i = 0; i < dataSize; i++)
    {
        if (data[i].harga < lowestPrice)
        {
            lowestPrice = data[i].harga;
            lowestPriceIndex = i;
        }
        if (lowestPrice == data[i].harga)
        {
            if (data[i].id < data[lowestPriceIndex].id)
            {
                lowestPriceIndex = i;
            }
        }
    }
    printf("Best item for price is: ");
    printData(data, lowestPriceIndex);
}

void lookForQual(struct item data[], int dataSize)
{
    int bestQualIndex = 0;
    int bestQuality = -1;
    for (int i = 0; i < dataSize; i++)
    {
        if (data[i].kualitas > bestQuality)
        {
            bestQualIndex = i;
            bestQuality = data[i].kualitas;
        }
        if (bestQuality == data[i].kualitas)
        {
            if (data[i].id < data[bestQualIndex].id)
            {
                bestQualIndex = i;
            }
        }
    }
    printf("Best item for quality is : ");
    printData(data, bestQualIndex);
}

int main()
{
    int N;
    scanf("%d", &N);
    struct item data[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d %s %d %d", &data[i].id, data[i].nama, &data[i].harga, &data[i].kualitas);
    }
    lookForPrice(data, N);
    lookForQual(data, N);
}