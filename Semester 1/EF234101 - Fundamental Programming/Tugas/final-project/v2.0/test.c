#include <stdio.h>

int main(int argc, char const *argv[])
{
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
                printStartMenu(0);
                return;
            }
        }
        return 0;
    }
}