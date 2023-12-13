// #include <stdio.h>
// // ANSI escape codes for text formatting
// #define ANSI_COLOR_RED "\x1b[31m"
// #define ANSI_COLOR_BOLD "\x1b[1m"
// #define ANSI_COLOR_RESET "\x1b[0m"

// enum ArrowKeys
// {
//     UP_ARROW = 72,
//     DOWN_ARROW = 80,
//     LEFT_ARROW = 75,
//     RIGHT_ARROW = 77,
//     ENTER_KEY = 13,
//     ESC_KEY = 27
// };

// void clearScreen()
// {
//     system("cls"); // Clears the console screen
// }

// void printMenu(int selectedIndex)
// {
//     clearScreen();
//     // banner();
//     // Define menu options
//     char menuOptions[][10] = {"INSERT", "READ", "UPDATE", "DELETE", "EXIT"};
//     int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);

//     // Print menu with highlighting
//     for (int i = 0; i < numOptions; i++)
//     {
//         if (i == selectedIndex)
//         {
//             if (i == 4) // Check if it's the "EXIT" option
//                 printf(ANSI_COLOR_BOLD ANSI_COLOR_RED "[" ANSI_COLOR_RESET " " ANSI_COLOR_BOLD ANSI_COLOR_RED "%s" ANSI_COLOR_RESET " " ANSI_COLOR_BOLD ANSI_COLOR_RED "]" ANSI_COLOR_RESET " ", menuOptions[i]);
//             else
//                 printf("[ %s ] ", menuOptions[i]); // Highlight selected option
//         }
//         else
//             printf("  %s   ", menuOptions[i]);
//     }

//     printf("\n\nUse Left and Right arrow keys to navigate. Press ESC to exit.\n");
// }

// int handleArrowKey(int arrowKey, int *pointer)
// {
//     switch (arrowKey)
//     {
//     case LEFT_ARROW:
//         (*pointer)--;
//         if (*pointer < 0)
//             *pointer = 0;
//         break;
//     case RIGHT_ARROW:
//         (*pointer)++;
//         if (*pointer > 4)
//             *pointer = 4;
//         break;
//     default:
//         break;
//     }
//     return arrowKey;
// }

// void navigate()
// {
//     int selectedIndex = 0;
//     printMenu(selectedIndex);

//     int ch, pointer = 0;

//     while ((ch = _getch()) != ESC_KEY) // Continue until the user presses the escape key (ASCII code 27)
//     {
//         if (ch == 0 || ch == 224)
//         {
//             int arrowKeyCode = _getch();
//             int arrowValue = handleArrowKey(arrowKeyCode, &pointer);

//             if (arrowValue == LEFT_ARROW || arrowValue == RIGHT_ARROW)
//             {
//                 selectedIndex = pointer;
//                 printMenu(selectedIndex);
//             }
//         }
//         else if (ch == ENTER_KEY)
//         {
//             switch (selectedIndex)
//             {
//             case 0:
//                 // insertData();
//                 break;
//             case 1:
//                 // readData();
//                 break;
//             case 2:
//                 // updateData();
//                 break;
//             case 3:
//                 // deleteData();
//                 break;
//             case 4:
//                 printf("Exiting...");
//                 exit(0);
//             default:
//                 break;
//             }
//         }
//     }

//     printf("You pressed ESC key\n");
// }

// int main()
// {
//     navigate();
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define MAX_SIZE 100
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_BOLD "\x1b[1m"
#define ANSI_COLOR_RESET "\x1b[0m"

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

void clearScreen()
{
    system("cls");
}

void banner()
{
    printf("   ##########################################\n");
    printf("   #                                        #\n");
    printf("   #        Warung Makan Masa Depan         #\n");
    printf("   #               by : Mirai               #\n");
    printf("   #                                        #\n");
    printf("   ##########################################\n");
    printf("\n\n");
}

enum ArrowKeys
{
    UP_ARROW = 72,
    DOWN_ARROW = 80,
    LEFT_ARROW = 75,
    RIGHT_ARROW = 77,
    ENTER_KEY = 13,
    ESC_KEY = 27
};

void handleArrowKeyStartMenu(int arrowKey, int *pointer);
void insertData(dataContainer *container);
void displayData(dataContainer *container, int selectedIndex);

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

void printStartMenu(int selectedIndex)
{
    clearScreen();
    banner();
    char menuOptions[][10] = {"INSERT", "READ", "UPDATE", "DELETE", "EXIT"};
    int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);
    for (int i = 0; i < numOptions; i++)
    {
        if (i == selectedIndex)
        {
            if (i == 4)
                printf(ANSI_COLOR_BOLD ANSI_COLOR_RED "[" ANSI_COLOR_RESET " " ANSI_COLOR_BOLD ANSI_COLOR_RED "%s" ANSI_COLOR_RESET " " ANSI_COLOR_BOLD ANSI_COLOR_RED "]" ANSI_COLOR_RESET " ", menuOptions[i]);
            else
                printf("[ %s ] ", menuOptions[i]);
        }
        else
            printf("  %s   ", menuOptions[i]);
    }
    printf("\n\nUse Left and Right Arrow Keys to Navigate\nPress ESC to Exit.\n");
}

void navigateStartMenu(dataContainer *myContainer)
{
    int selectedIndex = 0;
    printStartMenu(selectedIndex);

    int ch, pointer = 0;
    while ((ch = _getch()) != ESC_KEY)
    {
        if (ch == 0 || ch == 224)
        {
            int arrowKeyCode = _getch();
            handleArrowKeyStartMenu(arrowKeyCode, &pointer);
            if (arrowKeyCode == LEFT_ARROW || arrowKeyCode == RIGHT_ARROW)
            {
                selectedIndex = pointer;
                printStartMenu(selectedIndex);
            }
        }
        else if (ch == ENTER_KEY)
        {
            switch (selectedIndex)
            {
            case 0:
                insertData(myContainer);
                break;
            case 1:
                displayData(myContainer, selectedIndex);
                break;
            case 2:
                // updateData();
                break;
            case 3:
                // deleteData();
                break;
            case 4:
                printf("Exiting...");
                exit(0);
            default:
                break;
            }
        }
    }
}

void handleArrowKeyStartMenu(int arrowKey, int *pointer)
{
    switch (arrowKey)
    {
    case LEFT_ARROW:
        (*pointer)--;
        if (*pointer < 0)
        {
            *pointer = 0;
        }
        break;
    case RIGHT_ARROW:
        (*pointer)++;
        if (*pointer > 4)
        {
            *pointer = 4;
        }
        break;
    default:
        break;
    }
}

void insertData(dataContainer *container)
{
    readFromFile(container);
    if (container->indexKategori >= MAX_SIZE)
    {
        printf("Cannot add more categories. Maximum reached.\n");
        return;
    }

    char categoryName[MAX_SIZE];
    printf("Masukkan nama kategori: ");
    fgets(categoryName, sizeof(categoryName), stdin);
    categoryName[strcspn(categoryName, "\n")] = '\0'; // remove the newline character

    int existingIndex = -1;
    for (int i = 0; i < container->indexKategori; i++)
    {
        if (strcasecmp(container->category[i].namaKategori, categoryName) == 0)
        {
            existingIndex = i;
            break;
        }
    }

    if (existingIndex != -1)
    {
        kategori *currentKategori = &container->category[existingIndex];

        printf("Berapa item yang ingin dimasukkan: ");
        int numItemsToAdd;
        if (scanf("%d", &numItemsToAdd) != 1)
        {
            printf("Invalid input. Exiting...\n");
            return;
        }
        // Clear the input buffer
        while (getchar() != '\n')
            ;

        printf("Masukkan detail produk\n");
        for (int i = currentKategori->indexProduk; i < currentKategori->indexProduk + numItemsToAdd; i++)
        {
            printf("Item %d\n", i + 1);
            printf("Nama produk: ");
            fgets(currentKategori->products[i].namaProduk, sizeof(currentKategori->products[i].namaProduk), stdin);
            currentKategori->products[i].namaProduk[strcspn(currentKategori->products[i].namaProduk, "\n")] = '\0'; // remove the newline character

            printf("Harga produk: ");
            if (scanf("%d", &currentKategori->products[i].hargaProduk) != 1)
            {
                printf("Invalid input. Exiting...\n");
                return;
            }
            // Clear the input buffer
            while (getchar() != '\n')
                ;
        }

        currentKategori->indexProduk += numItemsToAdd;
    }
    else
    {
        if (container->indexKategori >= MAX_SIZE)
        {
            printf("Database penuh!\n");
            return;
        }

        kategori *currentKategori = &container->category[container->indexKategori];

        printf("Berapa item yang ingin dimasukkan: ");
        if (scanf("%d", &currentKategori->indexProduk) != 1)
        {
            printf("Invalid input. Exiting...\n");
            return;
        }
        // Clear the input buffer
        while (getchar() != '\n')
            ;

        if (currentKategori->indexProduk > MAX_SIZE)
        {
            printf("Database penuh!\n");
            return;
        }

        strcpy(currentKategori->namaKategori, categoryName);

        printf("Masukkan detail produk:\n");
        for (int i = 0; i < currentKategori->indexProduk; i++)
        {
            printf("Item %d:\n", i + 1);
            printf("Nama produk: ");
            fgets(currentKategori->products[i].namaProduk, sizeof(currentKategori->products[i].namaProduk), stdin);
            currentKategori->products[i].namaProduk[strcspn(currentKategori->products[i].namaProduk, "\n")] = '\0'; // remove the newline character

            printf("Harga produk: ");
            if (scanf("%d", &currentKategori->products[i].hargaProduk) != 1)
            {
                printf("Invalid input. Exiting...\n");
                return;
            }
            // Clear the input buffer
            while (getchar() != '\n')
                ;
        }

        container->indexKategori++;
    }

    saveToFile(container);
    printf("Data inserted successfully.\n");
}

void displayData(dataContainer *container, int selectedIndex)
{
    int ch;
    clearScreen();
    banner();
    readFromFile(container);
    for (int i = 0; i < container->indexKategori; i++)
    {
        printf("=================== %s ===================\n", container->category[i].namaKategori);
        printf("%-25s%-10s\n", "Nama", "Harga");
        for (int j = 0; j < container->category[i].indexProduk; j++)
        {
            printf("%-25s%-10d\n", container->category[i].products[j].namaProduk, container->category[i].products[j].hargaProduk);
        }
    }

    if (selectedIndex == 1)
    {
        printf("\nPress ESC to go back to the start menu...\n");
    }

    while (selectedIndex == 1 && (ch = _getch()) != ESC_KEY)
    {
        // Do nothing
    }
    if (selectedIndex == 1)
    {
        navigateStartMenu(container);
    }
}

int main()
{
    clearScreen();
    dataContainer currentContainer;
    currentContainer.indexKategori = 0;
    navigateStartMenu(&currentContainer);

    return 0;
}