#include <stdio.h>

// reference https://www.youtube.com/watch?v=zpvDctj8mM4

int main()
{
    int input;
    scanf("%d", &input);
    int count = 0;
    for (int penyebut = 5; input / penyebut != 0; penyebut *= 5)
    {
        count += input / penyebut;
    }

    // printf("%d\n", count);
    if (count % 2 == 0)
    {
        printf("Mantap bang!!");
    }
    else
    {
        printf("Hadeh, kenapa ganjil sih!");
    }
}