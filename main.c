#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song
{
    char artist[100];
    char title[100];
    struct Song *next;
    struct Song *prev;
};

struct Song *head = NULL;

struct Song *createNode()
{
    struct Song *newNode = (struct Song *)malloc(sizeof(struct Song));
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void AddFirstSong(char *title, char *artist)
{
    struct Song *newNode = createNode();

    strcpy(newNode->title, title);
    strcpy(newNode->artist, artist);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    printf("Lagu \"%s\" dari Artist \"%s\" berhasil ditambahkan di awal playlist.\n", title, artist);
}

main()
{
    int choice;
    char titleSong[100], artistName[100];

    do
    {
        system("cls");
        printf("\n===PLAYLIST MUSIK===\n");
        printf("1. Tambah Lagu Ke Playlist Awal\n");
        printf("2. Tambah Lagu Ke Playlist Akhir\n");
        printf("3. Tambah Lagu Setelah Lagu Tertentu\n");
        printf("4. Hapus Lagu Dari Playlist Awal\n");
        printf("5. Hapus Lagu Dari Playlist Akhir\n");
        printf("6. Tampilkan Seluruh Lagu\n");
        printf("7. Cari Lagu Berdasarkan Artist/Judul\n");
        printf("8. Mainkan Lagu Selanjutnya\n");
        printf("9. Mainkan Lagu Sebelumnya\n");
        printf("10. Tampilkan Lagu Yang Sedang Diputar\n");

        printf("0. Keluar\n");
        printf("Pilih Menu : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Masukan Judul Lagu : ");
            scanf(" %[^\n]", &titleSong);
            printf("Masukan Nama Artist : ");
            scanf(" %[^\n]", &artistName);
            if (strlen(titleSong) == 0 || strlen(artistName) == 0)
            {
                printf("Judul Lagu/Nama Artist Tidak Boleh Kosong");
            }
            else
            {
                AddFirstSong(titleSong, artistName);
            }

            break;
        case 2:
            // Fungsi Tambah Lagu Ke Playlist Akhir
            break;
        case 3:
            // Tambah Lagu Setelah Lagu Tertentu
            break;
        case 4:
            // Hapus Lagu Dari Playlist Awal
            break;
        case 5:
            // Hapus Lagu Dari Playlist Akhir
            break;
        case 6:
            // Tampilkan Seluruh Lagu
            break;
        case 7:
            // Cari Lagu Berdasarkan Artist/Judul
            break;
        case 8:
            // Mainkan Lagu Selanjutnya
            break;
        case 9:
            // Mainkan Lagu Sebelumnya
            break;
        case 10:
            // Tampilkan Lagu Yang Sedang Diputar
            break;
        default:
            break;
        }

        system("pause");
    } while (choice != 0);
}