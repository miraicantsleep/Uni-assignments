#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    // Open the file for writing random IDs
    FILE *idFile = fopen("output_ids.txt", "w");

    if (idFile == NULL)
    {
        perror("Error opening ID file");
        return 1;
    }

    // Generate random IDs
    for (int i = 0; i < 1000; i++)
    {
        // Generate a random ID in the range from 1 to 100
        int id = rand() % 100 + 1;

        // Print the ID to the file
        fprintf(idFile, "P%05d\n", id);
    }

    // Close the ID file
    fclose(idFile);

    return 0;
}