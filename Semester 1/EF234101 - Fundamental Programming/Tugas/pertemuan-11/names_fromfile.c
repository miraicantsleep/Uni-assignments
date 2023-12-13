#include <stdio.h>
#include <string.h>

int main()
{
    char input[90];
    char surname[20];
    char first[15];
    char middle[60];
    FILE *Inputfile = fopen("input.txt", "r");
    
    while (fgets(input, sizeof(input), Inputfile) != NULL)
    {
        int length = strlen(input);
        int counter = 0;
        for (int i = 0; i < 15; i++)
        {
            surname[i] = input[counter];
            if (surname[i] == ',')
            {
                surname[i] = '\0';
                counter++;
                break;
            }
            counter++;
        }
        printf("%s ", surname);

        // Find next alphabet
        for (int i = counter; i < 90; i++)
        {
            if (input[i] >= 'A' && input[i] <= 'Z')
            {
                counter = i;
                break;
            }
        }
        if (counter <= length)
        {
            for (int i = 0; i < 10; i++)
            {
                first[i] = input[counter];
                if (first[i] == ' ' || first[i] == '.')
                {
                    first[i] = '\0';
                    counter++;
                    break;
                }
                counter++;
            }
        }
        else
        {
            return 0;
        }
        printf("%s ", first);
        // Find next alphabet
        for (int i = counter; i < 90; i++)
        {
            if (input[i] >= 'A' && input[i] <= 'Z')
            {
                counter = i;
                break;
            }
        }
        if (counter <= length)
        {
            for (int i = 0; i < 10; i++)
            {
                middle[i] = input[counter];
                if (middle[i] == ' ' || middle[i] == '.')
                {
                    middle[i] = '\0';
                    counter++;
                    break;
                }
                counter++;
            }
        }
        printf("%s\n", middle);
    }
    fclose(Inputfile);
    return 0;
}
