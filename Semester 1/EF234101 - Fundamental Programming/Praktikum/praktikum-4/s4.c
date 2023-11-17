#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct mahasiswa
{
    char nama[40];
    char NRP[20];
    int angkatan;
    char asal[60];
};



int main(){
    int N;
    scanf("%d", &N);
    struct mahasiswa input[N];
    for (int i = 0; i < N; i++)
    {
        fgets(input[i].nama, sizeof(input[i].nama), stdin);
        scanf("%s", input[i].NRP);
        getchar();
        scanf("%d ", &input[i].angkatan);
        

    }
    
}