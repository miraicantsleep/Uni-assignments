#include <stdio.h>
// reference https://www.geeksforgeeks.org/square-root-of-a-perfect-square/
// Babylonian method

float findRoot(float input)
{
    float NextGuess = input;
    float LastGuess = 1.0;
    float accuracy = 0.005;
    while (NextGuess - LastGuess > accuracy)
    {
        NextGuess = 0.5 * (LastGuess + (input / LastGuess));
        LastGuess = input / NextGuess;
    }
    return NextGuess;
}

int main()
{
    float N;
    printf("Masukkan angka yang ingin di akarkan >> ");
    scanf("%f", &N);
    float root = findRoot(N);
    printf("Aproksimasi akar dari %.4f adalah %f\n", N, root);
}