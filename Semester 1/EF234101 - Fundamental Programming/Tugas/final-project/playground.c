#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct
{
    char namaProduk[MAX_SIZE];
    int hargaProduk;
} produk;

typedef struct
{
    char namaKategori[MAX_SIZE];
    produk products[MAX_SIZE];
    int indexProduk;
} kategori;

typedef struct
{
    int indexKategori;
    kategori category[MAX_SIZE];
} dataContainer;

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void readFromFile(dataContainer *container)
{
    FILE *database = fopen("data.dat", "rb");
    if (database == NULL)
    {
        printf("File database tidak bisa dibuka. Masukkan data terlebih dahulu.\n");
        return;
    }

    fread(&container->indexKategori, sizeof(int), 1, database);
    for (int i = 0; i < container->indexKategori; i++)
    {
        fread(container->category[i].namaKategori, sizeof(char), MAX_SIZE, database);
        fread(&container->category[i].indexProduk, sizeof(int), 1, database);
        for (int j = 0; j < container->category[i].indexProduk; j++)
        {
            fread(container->category[i].products[j].namaProduk, sizeof(char), MAX_SIZE, database);
            fread(&container->category[i].products[j].hargaProduk, sizeof(int), 1, database);
        }
    }
    fclose(database);
}

void saveToFile(dataContainer *container)
{
    FILE *database = fopen("data.dat", "wb");
    if (database == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(&container->indexKategori, sizeof(int), 1, database);
    for (int i = 0; i < container->indexKategori; i++)
    {
        fwrite(container->category[i].namaKategori, sizeof(char), MAX_SIZE, database);
        fwrite(&container->category[i].indexProduk, sizeof(int), 1, database);
        for (int j = 0; j < container->category[i].indexProduk; j++)
        {
            fwrite(container->category[i].products[j].namaProduk, sizeof(char), MAX_SIZE, database);
            fwrite(&container->category[i].products[j].hargaProduk, sizeof(int), 1, database);
        }
    }
    fclose(database);
}

void insertData(dataContainer *myContainer)
{
    readFromFile(myContainer);
    char queryKategori[MAX_SIZE];
    printf("Masukkan nama kategori: ");
    gets(queryKategori);
    int saveIndexKategori = -1;
    for (int i = 0; i < myContainer->indexKategori; i++)
    {
        if (strcasecmp(queryKategori, myContainer->category[i].namaKategori) == 0)
        {
            saveIndexKategori = i;
            break;
        }
    }
    if (saveIndexKategori != -1)
    {
        kategori *currentKategori = &myContainer->category[saveIndexKategori];
        printf("Kategori %s ditemukan!\n", queryKategori);
        char queryProduk[MAX_SIZE];
        printf("Masukkan nama produk: ");
        gets(queryProduk);
        int saveIndexProduk = -1;
        for (int i = 0; i < currentKategori->indexProduk; i++)
        {
            if (strcasecmp(queryProduk, currentKategori->products[i].namaProduk) == 0)
            {
                printf("Produk sudah ada, untuk update gunakan fitur UPDATE\n");
                return; // Exit the function if the product already exists
            }
        }

        // If we are here, the product doesn't exist, continue with adding a new product
        if (currentKategori->indexProduk < MAX_SIZE)
        {
            kategori *currentProduct = currentKategori; // Pointer to the current category

            // Prompt for details of the new product
            printf("Masukkan detail produk:\n");
            printf("Nama produk: ");
            gets(currentProduct->products[currentProduct->indexProduk].namaProduk);

            printf("Harga produk: ");
            scanf("%d", &currentProduct->products[currentProduct->indexProduk].hargaProduk);
            clearInputBuffer(); // Clear input buffer to prevent issues with the next input

            // Increment the index of products in the current category
            currentProduct->indexProduk++;

            // Save the changes to the file
            saveToFile(myContainer);

            printf("Data produk berhasil dimasukkan.\n");
        }
        else
        {
            printf("Kategori penuh! Tidak dapat menambahkan produk lebih lanjut.\n");
        }
    }
    else
    {
        // If the category is not found, create a new category
        if (myContainer->indexKategori < MAX_SIZE)
        {
            kategori *newKategori = &myContainer->category[myContainer->indexKategori];

            // Set the name of the new category
            strcpy(newKategori->namaKategori, queryKategori);

            // Prompt for details of the new product
            printf("Masukkan detail produk:\n");
            printf("Nama produk: ");
            gets(newKategori->products[newKategori->indexProduk].namaProduk);

            printf("Harga produk: ");
            scanf("%d", &newKategori->products[newKategori->indexProduk].hargaProduk);
            clearInputBuffer(); // Clear input buffer to prevent issues with the next input

            // Increment the index of products in the new category
            newKategori->indexProduk++;

            // Increment the index of categories
            myContainer->indexKategori++;

            // Save the changes to the file
            saveToFile(myContainer);

            printf("Data kategori dan produk baru berhasil dimasukkan.\n");
        }
        else
        {
            printf("Database penuh! Tidak dapat menambahkan kategori baru.\n");
        }
    }
}

int main()
{
    printf("1. Insert data\n");
    printf("2. Read Data\n");
    printf("3. Exit\n");
    dataContainer currentContainer;
    currentContainer.indexKategori = 0;
    int input;
    scanf("%d", &input);
    clearInputBuffer();
    switch (input)
    {
    case 1:
        insertData(&currentContainer);
        break;

    case 2:
        // readData(&currentContainer);
        break;
    case 3:
        exit(EXIT_SUCCESS);
        break;
    default:
        break;
    }
}