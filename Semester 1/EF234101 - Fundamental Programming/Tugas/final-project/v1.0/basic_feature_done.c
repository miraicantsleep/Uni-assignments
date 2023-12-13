#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void printUI()
{
    printf("1. Insert data\n");
    printf("2. Read data\n");
    printf("3. Update data\n");
    printf("4. Delete data\n");
    printf("5. Exit\n");
}

typedef struct
{
    char nama[MAX_SIZE];
    int harga;
} items;

typedef struct
{
    char kategoriName[MAX_SIZE];
    items item[MAX_SIZE];
    int totalItemInKat;
} kategori;

typedef struct
{
    int totalKat;
    kategori kategoris[MAX_SIZE];
} DataContainer;

void saveToFile(const DataContainer *dataContainer)
{
    FILE *file = fopen("data.dat", "wb");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    fwrite(&dataContainer->totalKat, sizeof(int), 1, file);

    for (int i = 0; i < dataContainer->totalKat; i++)
    {
        fwrite(dataContainer->kategoris[i].kategoriName, sizeof(char), MAX_SIZE, file);
        fwrite(&dataContainer->kategoris[i].totalItemInKat, sizeof(int), 1, file);

        for (int j = 0; j < dataContainer->kategoris[i].totalItemInKat; j++)
        {
            fwrite(dataContainer->kategoris[i].item[j].nama, sizeof(char), MAX_SIZE, file);
            fwrite(&dataContainer->kategoris[i].item[j].harga, sizeof(int), 1, file);
        }
    }

    fclose(file);
}

void readFromFile(DataContainer *dataContainer)
{
    FILE *file = fopen("data.dat", "rb");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }

    fread(&dataContainer->totalKat, sizeof(int), 1, file);

    for (int i = 0; i < dataContainer->totalKat; i++)
    {
        fread(dataContainer->kategoris[i].kategoriName, sizeof(char), MAX_SIZE, file);
        fread(&dataContainer->kategoris[i].totalItemInKat, sizeof(int), 1, file);

        for (int j = 0; j < dataContainer->kategoris[i].totalItemInKat; j++)
        {
            fread(dataContainer->kategoris[i].item[j].nama, sizeof(char), MAX_SIZE, file);
            fread(&dataContainer->kategoris[i].item[j].harga, sizeof(int), 1, file);
        }
    }

    fclose(file);
}

void insertData(DataContainer *dataContainer)
{
    readFromFile(dataContainer); // baca dari data dulu baru di insert
    if (dataContainer->totalKat >= MAX_SIZE)
    {
        printf("Cannot add more categories. Maximum reached.\n");
        return;
    }

    char categoryName[MAX_SIZE];
    printf("Enter category name: ");
    scanf("%s", categoryName);

    // Check if the category already exists
    int existingIndex = -1;
    for (int i = 0; i < dataContainer->totalKat; i++)
    {
        if (strcmp(dataContainer->kategoris[i].kategoriName, categoryName) == 0)
        {
            existingIndex = i;
            break;
        }
    }

    if (existingIndex != -1)
    {
        // Category already exists, add items to the existing category
        kategori *currentKategori = &dataContainer->kategoris[existingIndex];

        printf("Enter the number of items to add to the category: ");
        int numItemsToAdd;
        scanf("%d", &numItemsToAdd);

        if (currentKategori->totalItemInKat + numItemsToAdd > MAX_SIZE)
        {
            printf("Cannot add more items. Maximum items reached for the category.\n");
            return;
        }

        printf("Enter additional item details:\n");
        for (int i = currentKategori->totalItemInKat; i < currentKategori->totalItemInKat + numItemsToAdd; i++)
        {
            printf("Item %d:\n", i + 1);
            printf("Name: ");
            scanf("%s", currentKategori->item[i].nama);
            printf("Price: ");
            scanf("%d", &currentKategori->item[i].harga);
        }

        currentKategori->totalItemInKat += numItemsToAdd;
    }
    else
    {
        // Category does not exist, create a new category
        if (dataContainer->totalKat >= MAX_SIZE)
        {
            printf("Cannot add more categories. Maximum reached.\n");
            return;
        }

        kategori *currentKategori = &dataContainer->kategoris[dataContainer->totalKat];

        printf("Enter the number of items in the category: ");
        scanf("%d", &currentKategori->totalItemInKat);

        if (currentKategori->totalItemInKat > MAX_SIZE)
        {
            printf("Cannot add more items. Maximum items reached for the category.\n");
            return;
        }

        strcpy(currentKategori->kategoriName, categoryName);

        printf("Enter item details:\n");
        for (int i = 0; i < currentKategori->totalItemInKat; i++)
        {
            printf("Item %d:\n", i + 1);
            printf("Name: ");
            scanf("%s", currentKategori->item[i].nama);
            printf("Price: ");
            scanf("%d", &currentKategori->item[i].harga);
        }

        dataContainer->totalKat++;
    }

    saveToFile(dataContainer);
    printf("Data inserted successfully.\n");
}

void readData(DataContainer *dataContainer)
{
    // Load data from file before displaying
    readFromFile(dataContainer);

    for (int i = 0; i < dataContainer->totalKat; i++)
    {
        printf("================ %s ================\n", dataContainer->kategoris[i].kategoriName);
        printf("%-25s%-10s\n", "Nama", "Harga");

        for (int j = 0; j < dataContainer->kategoris[i].totalItemInKat; j++)
        {
            printf("%-25s%-10d\n", dataContainer->kategoris[i].item[j].nama, dataContainer->kategoris[i].item[j].harga);
        }
    }
}

void updateData(DataContainer *dataContainer)
{
    char categoryName[MAX_SIZE];
    printf("Enter category name: ");
    scanf("%s", categoryName);

    // Check if the category exists
    int categoryIndex = -1;
    for (int i = 0; i < dataContainer->totalKat; i++)
    {
        if (strcmp(dataContainer->kategoris[i].kategoriName, categoryName) == 0)
        {
            categoryIndex = i;
            break;
        }
    }

    if (categoryIndex == -1)
    {
        printf("Category not found.\n");
        return;
    }

    // Category found, ask if user wants to update the price or name
    printf("1. Update item price\n");
    printf("2. Update item name\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    kategori *currentKategori = &dataContainer->kategoris[categoryIndex];

    if (choice == 1)
    {
        // Update item price
        printf("Enter the name of the item to update price: ");
        char itemName[MAX_SIZE];
        scanf("%s", itemName);

        int itemIndex = -1;
        for (int i = 0; i < currentKategori->totalItemInKat; i++)
        {
            if (strcmp(currentKategori->item[i].nama, itemName) == 0)
            {
                itemIndex = i;
                break;
            }
        }

        if (itemIndex == -1)
        {
            printf("Item not found in the category.\n");
            return;
        }

        // Update the price
        printf("Enter the new price: ");
        scanf("%d", &currentKategori->item[itemIndex].harga);
    }
    else if (choice == 2)
    {
        // Update item name
        printf("Enter the current name of the item: ");
        char itemName[MAX_SIZE];
        scanf("%s", itemName);

        int itemIndex = -1;
        for (int i = 0; i < currentKategori->totalItemInKat; i++)
        {
            if (strcmp(currentKategori->item[i].nama, itemName) == 0)
            {
                itemIndex = i;
                break;
            }
        }

        if (itemIndex == -1)
        {
            printf("Item not found in the category.\n");
            return;
        }

        // Update the name
        printf("Enter the new name: ");
        scanf("%s", currentKategori->item[itemIndex].nama);
    }
    else
    {
        printf("Invalid choice.\n");
        return;
    }

    // Save the changes to the file
    saveToFile(dataContainer);

    printf("Data updated successfully.\n");
}

void deleteData(DataContainer *dataContainer)
{
    char categoryName[MAX_SIZE];
    printf("Enter category name to delete: ");
    scanf("%s", categoryName);

    // Check if the category exists
    int categoryIndex = -1;
    for (int i = 0; i < dataContainer->totalKat; i++)
    {
        if (strcmp(dataContainer->kategoris[i].kategoriName, categoryName) == 0)
        {
            categoryIndex = i;
            break;
        }
    }

    if (categoryIndex == -1)
    {
        printf("Category not found.\n");
        return;
    }

    // Category found, ask if user wants to delete the entire category or just an item
    printf("1. Delete entire category\n");
    printf("2. Delete specific item in the category\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        // Delete entire category
        for (int i = categoryIndex; i < dataContainer->totalKat - 1; i++)
        {
            dataContainer->kategoris[i] = dataContainer->kategoris[i + 1];
        }
        dataContainer->totalKat--;
        break;

    case 2:
        // Delete specific item in the category
        printf("Enter the name of the item to delete: ");
        char itemName[MAX_SIZE];
        scanf("%s", itemName);

        int itemIndex = -1;
        kategori *currentKategori = &dataContainer->kategoris[categoryIndex];
        for (int i = 0; i < currentKategori->totalItemInKat; i++)
        {
            if (strcmp(currentKategori->item[i].nama, itemName) == 0)
            {
                itemIndex = i;
                break;
            }
        }

        if (itemIndex == -1)
        {
            printf("Item not found in the category.\n");
            return;
        }

        // Delete the item
        for (int i = itemIndex; i < currentKategori->totalItemInKat - 1; i++)
        {
            currentKategori->item[i] = currentKategori->item[i + 1];
        }
        currentKategori->totalItemInKat--;
        break;

    default:
        printf("Invalid choice.\n");
        return;
    }

    // Save the changes to the file
    saveToFile(dataContainer);

    printf("Data deleted successfully.\n");
}

int main()
{
    DataContainer dataContainer;
    dataContainer.totalKat = 0;
    system("cls");
    printUI();

    while (1)
    {
        int input;
        printf("Enter your choice: ");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            insertData(&dataContainer);
            break;
        case 2:
            readData(&dataContainer);
            break;
        case 3:
            updateData(&dataContainer);
            break;
        case 4:
            deleteData(&dataContainer);
            break;
        case 5:
            printf("Exiting the program.\n");
            return 0; // Exit the program when the user chooses option 3.
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }
    }

    return 0;
}