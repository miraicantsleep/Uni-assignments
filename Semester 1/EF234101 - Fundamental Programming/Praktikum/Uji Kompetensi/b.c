#include <stdio.h>
#include <string.h>


int main(){
    int N;
    scanf("%d", &N);
    for (int i = 1; i < N; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d ", i);
        }
    }
    if (N % 2 == 0)
    {
        printf("%d", N);
    }
    
    
    
}