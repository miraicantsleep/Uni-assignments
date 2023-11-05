#include <stdio.h>

long long row, column;
long long rowGepard, colGepard, rowPela, colPela;

int main()
{
    scanf("%lld %lld", &row, &column);
    scanf("%lld %lld %lld %lld", &rowGepard, &colGepard, &rowPela, &colPela);
    int ans = 4; // inisiasi max bayangan

    // check corner (kasus selalu tetap)
    // check corner gepard
    if (rowGepard == 1 || rowGepard == row)
    {
        if (colGepard == 1 || colGepard == column)
        {
            ans -= 2;
            printf("Tch EZPZ, aku cuma butuh %d bayangan biar gacor!", ans);
            return 0;
        }
        
    }
    // check corner pela
    else if (rowPela == 1 || rowPela == row)
    {
        if (colPela == 1 || colPela == column)
        {
            ans -= 2;
            printf("Tch EZPZ, aku cuma butuh %d bayangan biar gacor!", ans);
            return 0;
        }
        
    }
    
    
    // special case
    if (row < 4 || column < 4)
    {
        if (row > column)
        {
            ans = column;
        }
        else // ( row < column) / (row = column)
        {
            ans = row;
        }
        printf("Tch EZPZ, aku cuma butuh %d bayangan biar gacor!", ans);
        return 0;
    }
    else if (rowGepard == 1 || rowGepard == row || rowPela == 1 || rowPela == row) // cek row yang sama dengan 1 atau sama dengan max row
    {
        if (colGepard > 1 && colGepard < column) // jika dia di row = 1 atau = max row, cek col apakah > 1 dan < max col
        {
            ans -= 1;
            printf("Tch EZPZ, aku cuma butuh %d bayangan biar gacor!", ans);
            return 0;
        }
        if (colPela > 1 && colPela < column) // jika dia di row = 1 atau = max row, cek col apakah > 1 dan < max col
        {
            ans -= 1;
            printf("Tch EZPZ, aku cuma butuh %d bayangan biar gacor!", ans);
            return 0;
        }
    }
    else if (colGepard == 1 || colGepard == column || colPela == 1 || colPela == column) // cek row yang sama dengan 1 atau sama dengan max row
    {
        if (rowGepard > 1 && rowGepard < row) // jika dia di row = 1 atau = max row, cek col apakah > 1 dan < max col
        {
            ans -= 1;
            printf("Tch EZPZ, aku cuma butuh %d bayangan biar gacor!", ans);
            return 0;
        }
        if (rowPela > 1 && rowPela < row) // jika dia di row = 1 atau = max row, cek col apakah > 1 dan < max col
        {
            ans -= 1;
            printf("Tch EZPZ, aku cuma butuh %d bayangan biar gacor!", ans);
            return 0;
        }
    }
    else // tidak di bagian batas row dan col
    {
        printf("Tch EZPZ, aku cuma butuh %d bayangan biar gacor!", ans);
    }

    return 0;
}
