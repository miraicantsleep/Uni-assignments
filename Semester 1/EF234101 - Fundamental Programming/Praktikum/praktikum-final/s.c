#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct pahlawan
{
    int hp;
    float atk;
    char gender;
    char nama[150];
};

void checkPalindrome(struct pahlawan data[], int size)
{
    int start = 0;
    int end = size - 1;
    int index[size];
    int counter = 0;
    bool realPalindrome = true;
    while (start <= end)
    {
        bool isPalindrome = false;
        int palindromeCount = 0;
        if (data[start].hp == data[end].hp && palindromeCount < 2)
        {
            palindromeCount++;
        }
        if (data[start].atk == data[end].atk && palindromeCount < 2)
        {
            palindromeCount++;
        }
        if (data[start].gender == data[end].gender && palindromeCount < 2)
        {
            palindromeCount++;
        }
        if (strcmp(data[start].nama, data[end].nama) == 0 && palindromeCount < 2)
        {
            palindromeCount++;
        }
        if (palindromeCount == 2)
        {
            isPalindrome = true;
        }
        if (!isPalindrome)
        {
            index[counter] = start + 1;
            counter++;
            realPalindrome = false;
        }
        start++;
        end--;
    }
    if (realPalindrome)
    {
        printf("Siap perang, Dewi Shita!");
    }
    else
    {
        printf("Sebentar Dewi Shita, belum palindrom nih.\n");
        for (int i = counter - 1; i >= 0; i--)
        {
            index[counter] = size - index[i] + 1;
            counter++;
        }

        for (int i = 0; i < counter; i++)
        {
            printf("%d ", index[i]);
        }
    }
}

int main()
{
    int N;
    scanf("%d ", &N);
    struct pahlawan data[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d ", &data[i].hp);
        scanf("%f ", &data[i].atk);
        scanf("%c ", &data[i].gender);
        gets(data[i].nama);
    }
    checkPalindrome(data, N);
}