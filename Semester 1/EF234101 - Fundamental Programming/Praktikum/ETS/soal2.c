#include <stdio.h>

// https://www.programiz.com/c-programming/examples/reverse-number
// reference https://www.programiz.com/c-programming/examples/palindrome-number

// kalo angka 09 gimana?
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

int checkPalindrome(int input, int reversed){
    if (input == reversed)
    {
        printf("Angka tersebut adalah palindrom\n");
    }
    else printf("Angka tersebut tidak palindrom\n");
    
}

int main()
{
    int N;
    printf("Masukkan angka >> ");
    scanf("%d", &N);
    printf("Angka input adalah : %d\n", N);

    int reversedAngka = reversedFunc(N);
    printf("Angka reversed adalah : %d\n", reversedAngka);

    int apakahPrimaInput = checkPrime(N);
    if (apakahPrimaInput == 0)
    {
        printf("Angka input adalah prima\n");
    }
    else
    {
        printf("Angka input bukan prima\n");
    }

    int apakahPrimaReversed = checkPrime(reversedAngka);
    if (apakahPrimaReversed == 0)
    {
        printf("Angka reversed adalah prima\n");
    }
    else
    {
        printf("Angka reversed bukan prima\n");
    }

    checkPalindrome(N, reversedAngka);
}