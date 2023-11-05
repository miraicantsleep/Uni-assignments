#include <stdio.h>
#include <string.h>

int main()
{
    char cekString[105];
    char matrix[210][210];
    int row = 0;
    int column = 0;
    int columnCounter = 0;

    // printf("input: ");
    scanf("%[^\n]", cekString);
    getchar();

    int panjang = strlen(cekString);
    // printf("%d\n", panjang);
    char stringToFind[105];
    int j = 0;
    int foundDigit = 0;

    for (int i = 0; i < panjang; i++)
    {
        if (cekString[i] >= '0' && cekString[i] <= '9')
        {
            foundDigit = 1;
        }
        else if (foundDigit)
        {
            stringToFind[j++] = cekString[i];
        }
    }

    stringToFind[j] = '\0';
    int panjangString = strlen(stringToFind);

    // printf("string setelah digit: %s\n", stringToFind);

    while (scanf("%c", &matrix[row][column]) != EOF)
    {
        if (matrix[row][column] != '\n')
        {
            column++;
            columnCounter++;
        }
        else
        {
            column = 0;
            row++;
        }
    }
    columnCounter /= row;
    // printf("%d %d\n", row, columnCounter); // cek bentar bener ga ukuran matrix nya

    // buat row dan column dalam bentuk index array
    int indexRow = row - 1;
    int indexColumn = columnCounter - 1;

    // Print the matrix
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < columnCounter; j++)
        {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }

    // cek kiri ke kanan (kode ini bakal jadi template buat cek kanan ke kiri, atas bawah, bawah atas)
    char arrLefttoRight[105];
    char matchingPositionsLefttoRight[210][210];
    for (int i = 0; i < row; i++) // cek row sampe abis
    {
        int numMatches = 0;
        for (int j = 0; j < columnCounter; j++) // cek column sampe abis
        {
            if (matrix[i][j] == stringToFind[numMatches]) // compare antara isi matrix dengan isi stringtofind
            {
                matchingPositionsLefttoRight[i][j] = matrix[i][j];
                arrLefttoRight[numMatches] = matchingPositionsLefttoRight[i][j];
                numMatches++;
            }
            else
            {
                continue;
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < columnCounter; j++)
        {
            if (matchingPositionsLefttoRight[i][j] == '\0')
            {
                printf(".");
            }
            else
            {
                printf("%c", matchingPositionsLefttoRight[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("=====================kiri ke kanan======================");

    // cek kanan ke kiri
    
}