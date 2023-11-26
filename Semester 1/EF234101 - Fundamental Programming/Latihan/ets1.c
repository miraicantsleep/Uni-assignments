#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int input[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &input[i]);
    }

    int sorted = 0;
    while (!sorted) {
        sorted = 1;
        for (int i = 0; i < N-1; i++)
        {
            if (input[i] > input[i+1])
            {
                int temp = input[i];
                input[i] = input[i+1];
                input[i+1] = temp;
                sorted = 0;
            }
        }
    }


// count mean

printf("Minimum: %d\n", input[0]);
printf("Maximum: %d\n", input[N]);
// printf("Mode: %d", );

    return 0;
}
