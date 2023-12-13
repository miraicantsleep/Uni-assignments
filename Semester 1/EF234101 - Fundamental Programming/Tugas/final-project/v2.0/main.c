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
void updateData(dataContainer *container);
void deleteData(dataContainer *container);
void clearInputBuffer();

void readFromFile(dataContainer *container)
{
    FILE *database = fopen("data.txt", "r");
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
    FILE *database = fopen("data.txt", "w");
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
    printf("\n\nGunakan <- atau -> untuk navigasi.\nTekan ESC untuk keluar.\n");
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
                updateData(myContainer);
                break;
            case 3:
                deleteData(myContainer);
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

void insertData(dataContainer *myContainer)
{
    readFromFile(myContainer);
    displayData(myContainer, 0);
    char queryKategori[MAX_SIZE];
    printf("Masukkan nama kategori atau masukkan -1 untuk keluar: ");
    scanf("%99[^\n]", queryKategori);
    clearInputBuffer();
    if (strcmp(queryKategori, "-1") == 0)
    {
        clearScreen();
        printStartMenu(0);
        return;
    }

    int saveIndexKategori = -1;
    for (int i = 0; i < myContainer->indexKategori; i++)
    {
        if (strcasecmp(queryKategori, myContainer->category[i].namaKategori) == 0) // cari index kategori
        {
            saveIndexKategori = i;
            break;
        }
    }
    if (saveIndexKategori != -1) // kalo ketemu masukkan ke kategori tersebut
    {
        kategori *currentKategori = &myContainer->category[saveIndexKategori];
        printf("Kategori %s ditemukan!\n", queryKategori);
        char queryProduk[MAX_SIZE];
        printf("Masukkan nama produk: ");
        scanf("%99[^\n]", queryProduk);
        clearInputBuffer();
        for (int i = 0; i < currentKategori->indexProduk; i++)
        {
            if (strcasecmp(queryProduk, currentKategori->products[i].namaProduk) == 0) // cari produk, jika ketemu arahkan user ke update
            {
                printf("Produk sudah ada, untuk update gunakan fitur UPDATE\n");
                printf("Tekan tombol ESC untuk kembali...");
                int ch;
                while ((ch = _getch()) != ESC_KEY)
                {
                    /* code */
                }
                return;
                printStartMenu(0);
            }
        }

        // kalo nyampe sini, produk tersebut belum ada, masukkan ke database
        if (currentKategori->indexProduk < MAX_SIZE)
        {
            // kategori *currentProduct = currentKategori; // Pointer to the current category
            strcpy(currentKategori->products[currentKategori->indexProduk].namaProduk, queryProduk);

            printf("Harga produk: ");
            while (scanf("%d", &currentKategori->products[currentKategori->indexProduk].hargaProduk) != 1)
            {
                printf("Masukkan angka yang valid!\n");
                clearInputBuffer();
                printf("Harga produk: ");
            }
            clearInputBuffer();

            // Increment dalam current kateogri
            currentKategori->indexProduk++;

            // Save to file
            saveToFile(myContainer);
            printf("Data produk berhasil dimasukkan.\n");
            printf("Tekan tombol ESC untuk kembali...");
        }
        else
        {
            printf("Kategori penuh! Tidak dapat menambahkan produk lebih lanjut.\n");
            printf("Tekan tombol ESC untuk kembali...");
        }
    }
    else
    {
        // kategori nya ga ketemu, bikin baru
        if (myContainer->indexKategori < MAX_SIZE)
        {
            kategori *newKategori = &myContainer->category[myContainer->indexKategori];

            // Set nama kategori nya
            strcpy(newKategori->namaKategori, queryKategori);

            // masukkan detail produk
            printf("Nama produk: ");
            scanf("%99[^\n]", newKategori->products[newKategori->indexProduk].namaProduk);
            clearInputBuffer();

            printf("Harga produk: ");
            while (scanf("%d", &newKategori->products[newKategori->indexProduk].hargaProduk) != 1)
            {
                printf("Masukkan angka yang valid!\n");
                clearInputBuffer();
                printf("Harga produk: ");
            }
            clearInputBuffer();

            // naikin index produk di newKategori
            newKategori->indexProduk++;

            // naikin index kategori
            myContainer->indexKategori++;

            // simpen ke file
            saveToFile(myContainer);

            printf("Data kategori dan produk baru berhasil dimasukkan.\n");
            printf("Tekan tombol ESC untuk kembali.\n");
        }
        else
        {
            printf("Database penuh! Tidak dapat menambahkan kategori baru.\n");
            printf("Tekan tombol ESC untuk kembali.\n");
        }
    }

    int ch;
    while ((ch = _getch()) != ESC_KEY)
    {
        // Do nothing
    }
    clearScreen();
    printStartMenu(0);
}

void displayData(dataContainer *container, int selectedIndex)
{
    int ch;
    clearScreen();
    banner();
    readFromFile(container);
    for (int i = 0; i < container->indexKategori; i++)
    {
        printf("%s %s %s\n", "===============", container->category[i].namaKategori, "===============");
        printf("%-25s%-10s\n", "Nama", "Harga");
        for (int j = 0; j < container->category[i].indexProduk; j++)
        {
            printf("%-25s%-10d\n", container->category[i].products[j].namaProduk, container->category[i].products[j].hargaProduk);
        }
    }

    if (selectedIndex == 1)
    {
        printf("\nTekan ESC untuk kembali...");
    }

    while (selectedIndex == 1 && (ch = _getch()) != ESC_KEY)
    {
        // Do nothing
    }
    if (selectedIndex == 1)
    {
        printStartMenu(1);
    }
}

void updateData(dataContainer *myContainer)
{
    readFromFile(myContainer);
    char queryKategori[MAX_SIZE];
    displayData(myContainer, 3);
    printf("Masukkan nama kategori atau -1 untuk keluar: ");
    scanf("%99[^\n]", queryKategori);
    clearInputBuffer();
    if (strcmp(queryKategori, "-1") == 0)
    {
        clearScreen();
        printStartMenu(2);
        return;
    }

    // cek kalo kategori nya ada
    int saveIndexKategori = -1;
    for (int i = 0; i < myContainer->indexKategori; i++)
    {
        if (strcasecmp(myContainer->category[i].namaKategori, queryKategori) == 0)
        {
            saveIndexKategori = i;
            break;
        }
    }

    if (saveIndexKategori == -1)
    {
        printf("Kategori tidak ditemukan!\n"); // gak ketemu langsung return
        printf("Tekan tombol ESC untuk kembali...");
        int ch;
        while ((ch = _getch()) != ESC_KEY)
        {
            /* code */
        }
        clearScreen();
        printStartMenu(2);
        return;
    }

    // kategori nya ketemu,
    printf("1. Update Nama Kategori\n");
    printf("2. Update Harga Produk\n");
    printf("3. Update Nama Produk\n");
    int input;
    printf("Masukkan pilihan: ");
    while (scanf("%d", &input) != 1 || (input != 1 && input != 2 && input != 3))
    {
        printf("Input tidak valid!\n");
        printf("Masukkan pilihan: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    kategori *currentKategori = &myContainer->category[saveIndexKategori];

    if (input == 1)
    {
        printf("Nama kategori sekarang -> %s\n", currentKategori->namaKategori);
        printf("Masukkan nama kategori baru: ");
        scanf("%[^\n]", currentKategori->namaKategori);
        clearInputBuffer();
    }
    else if (input == 2)
    {
        // Update item price
        printf("Masukkan nama produk yang ingin diubah harga nya: ");
        char queryProduk[MAX_SIZE];
        scanf("%99[^\n]", queryProduk);
        clearInputBuffer();

        int saveProdukIndex = -1;
        for (int i = 0; i < currentKategori->indexProduk; i++)
        {
            if (strcasecmp(currentKategori->products[i].namaProduk, queryProduk) == 0)
            {
                saveProdukIndex = i;
                break;
            }
        }

        if (saveProdukIndex == -1)
        {
            printf("Produk tidak ditemukan pada kategori!\n");
            printf("Tekan tombol ESC untuk kembali...");
            int ch;
            while ((ch = _getch()) != ESC_KEY)
            {
                /* code */
            }
            printStartMenu(2);
            return;
        }

        // Update the price
        printf("Masukkan harga baru: ");
        while (scanf("%d", &currentKategori->products[saveProdukIndex].hargaProduk) != 1)
        {
            printf("Masukkan angka yang valid!\n");
            clearInputBuffer();
            printf("Masukkan harga baru: ");
        }
        clearInputBuffer();
    }
    else if (input == 3)
    {
        // Update item name
        printf("Masukkan nama produk saat ini: ");
        char queryProduk[MAX_SIZE];
        scanf("%99[^\n]", queryProduk);
        clearInputBuffer();
        int saveProdukIndex = -1;
        for (int i = 0; i < currentKategori->indexProduk; i++)
        {
            if (strcasecmp(currentKategori->products[i].namaProduk, queryProduk) == 0)
            {
                saveProdukIndex = i;
                break;
            }
        }

        if (saveProdukIndex == -1)
        {
            printf("Item %s tidak ditemukan pada kategori!\n", queryProduk);
            printf("Tekan tombol ESC untuk kembali...");
            int ch;
            while ((ch = _getch()) != ESC_KEY)
            {
                // loop nya jalan terus kalo bukan esc
            }
            printStartMenu(2);
            return;
        }
        else
        {
            // Update namanya
            printf("Nama lama -> %s\n", currentKategori->products[saveProdukIndex].namaProduk);
            printf("Masukkan nama baru: ");
            scanf("%99[^\n]", currentKategori->products[saveProdukIndex].namaProduk);
            clearInputBuffer();
        }
    }
    // Save the changes to the file
    saveToFile(myContainer);
    printf("Data telah ter-update!\n");
    printf("Tekan tombol ESC untuk kembali...");
    int ch;
    while ((ch = _getch()) != ESC_KEY)
    {
        /* code */
    }
    printStartMenu(2);
    return;
}

void deleteData(dataContainer *myContainer)
{
    readFromFile(myContainer);
    displayData(myContainer, 3);
    char queryKategori[MAX_SIZE];
    printf("Masukkan nama kategori atau -1 untuk keluar: ");
    scanf("%99[^\n]", queryKategori);
    clearInputBuffer();
    if (strcmp(queryKategori, "-1") == 0)
    {
        clearScreen();
        printStartMenu(3);
        return;
    }
    // Check if the category exists
    int saveIndexKategori = -1;
    for (int i = 0; i < myContainer->indexKategori; i++)
    {
        if (strcasecmp(myContainer->category[i].namaKategori, queryKategori) == 0)
        {
            saveIndexKategori = i;
            break;
        }
    }

    if (saveIndexKategori == -1)
    {
        printf("Kategori %s tidak ditemukan.\n", queryKategori);
        printf("Tekan tombol ESC untuk kembali...");
        int ch;
        while ((ch = _getch()) != ESC_KEY)
        {
            /* code */
        }
        printStartMenu(3);
        return;
    }

    // kategori nya ketemu
    printf("1. Hapus isi seluruh kategori\n");
    printf("2. Hapus produk dalam kategori\n");
    int input;
    printf("Masukkan pilihan: ");
    while (scanf("%d", &input) != 1 || (input != 1 && input != 2))
    {
        printf("Input tidak valid!\n");
        printf("Masukkan pilihan: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    switch (input)
    {
    case 1:
        // Delete entire category
        for (int i = saveIndexKategori; i < myContainer->indexKategori - 1; i++)
        {
            myContainer->category[i] = myContainer->category[i + 1];
        }
        myContainer->indexKategori--;
        break;

    case 2:
        // hapus spesific item dalam kategori
        printf("Kategori terpilih -> %s\n", myContainer->category[saveIndexKategori].namaKategori);
        printf("Masukkan nama produk yang ingin dihapus: ");
        char queryProduk[MAX_SIZE];
        scanf("%99[^\n]", queryProduk);
        clearInputBuffer();
        int saveProdukIndex = -1;
        kategori *currentKategori = &myContainer->category[saveIndexKategori];
        for (int i = 0; i < currentKategori->indexProduk; i++)
        {
            if (strcasecmp(currentKategori->products[i].namaProduk, queryProduk) == 0)
            {
                saveProdukIndex = i;
                break;
            }
        }

        if (saveProdukIndex == -1)
        {
            printf("Produk %s tidak ditemukan.\n", queryProduk);
            printf("Tekan tombol ESC untuk kembali...");
            int ch;
            while ((ch = _getch()) != ESC_KEY)
            {
                /* code */
            }
            printStartMenu(3);
            return;
        }

        // Delete the item
        for (int i = saveProdukIndex; i < currentKategori->indexProduk - 1; i++)
        {
            currentKategori->products[i] = currentKategori->products[i + 1];
        }
        currentKategori->indexProduk--;
        break;

    default:
        printf("Invalid choice.\n");
        return;
    }

    // Save the changes to the file
    saveToFile(myContainer);

    printf("Data telah terhapus!\n");
    printf("Tekan tombol ESC untuk kembali...");
    int ch;
    while ((ch = _getch()) != ESC_KEY)
    {
        /* code */
    }
    printStartMenu(3);
    return;
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{
    clearScreen();
    dataContainer currentContainer;
    currentContainer.indexKategori = 0;
    navigateStartMenu(&currentContainer);

    return 0;
}