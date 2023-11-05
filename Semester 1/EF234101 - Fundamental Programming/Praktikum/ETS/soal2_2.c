// reference https://www.geeksforgeeks.org/check-if-a-string-is-palindrome-in-c-using-pointers/
// reference https://www.geeksforgeeks.org/sprintf-in-c/

#include <stdio.h>
#include <string.h>

int reversedFunc(int input)
{
    int checkNum = input;
    int reversed = 0;
    int sisa;

    while (checkNum > 0)
    {
        sisa = checkNum % 10;
        reversed = reversed * 10 + sisa;
        checkNum /= 10;
    }
    return reversed;
}

int checkPrime(int input)
{
    for (int i = 2; i <= input / 2; i++)
    {
        if (input % i != 0)
        {
            continue;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

void checkPalindrome(char *string)
{
    char *p, *reversed;
    p = string;

    while (*p != '\0')
    {
        ++p;
    }
    --p;

    for (reversed = string; p >= reversed;)
    {
        if (*p == *reversed)
        {
            --p;
            reversed++;
        }
        else
        {
            break;
        }
    }
    if (reversed > p)
    {
        printf("Angka palindrom.\n");
    }
    else
    {
        printf("Angka tidak palindrom.\n");
    }
}

int main()
{
    int N;
    char arr[1000];
    printf("Masukkan angka >> ");
    scanf("%d", &N);
    sprintf(arr, "%d", N); // convert to string, nanti ini dipake di akhir
    int length = strlen(arr);
    printf("Angka input adalah : %d.\n", N);

    char arrRev[1000];
    int counter = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        arrRev[counter] = arr[i];
        counter++;
    }
    arrRev[counter] = '\0';
    printf("Angka reversed adalah %s.\n", arrRev);

    int apakahPrimaInput = checkPrime(N);
    if (apakahPrimaInput == 0)
    {
        printf("Angka input adalah prima.\n");
    }
    else
    {
        printf("Angka input bukan prima.\n");
    }

    // int reversedAngka = reversedFunc(N); // ini ntar buat cek reverse angka prime
    // int apakahPrimaReversed = checkPrime(reversedAngka);
    // if (apakahPrimaReversed == 0)
    // {
    //     printf("Angka reversed adalah prima.\n");
    // }
    // else
    // {
    //     printf("Angka reversed bukan prima.\n");
    // }

    checkPalindrome(arr);
}