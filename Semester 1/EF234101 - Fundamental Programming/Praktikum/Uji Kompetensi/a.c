#include <stdio.h>
#include <string.h>


int main(){
    char arr[101];
    scanf("%s", arr);
    int length = strlen(arr);
    for (int i = length-1; i >= 0; i--)
    {
        printf("%c", arr[i]);
    }
    
}