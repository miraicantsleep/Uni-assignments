#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
    char str[200];
    int offset;
    scanf("%s", str);
    scanf("%d", &offset);
    for (int i = 0; i < str[i] != '\0'; i++)
    {
        if (isupper(str[i]))
        {
            str[i] = ((str[i] - 'A' + offset) % 26 + 'A');
        }
        if (islower(str[i]))
        {
            str[i] = ((str[i] - 'a' + offset) % 26 + 'a');
        }
    }
    printf("%s", str);
}