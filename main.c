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

void AddLastSong(char *title, char *artist)
{
    struct Song *newNode = createNode();

    strcpy(newNode->title, title);
    strcpy(newNode->artist, artist);

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    struct Song *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;

    printf("Lagu \"%s\" dari Artist \"%s\" berhasil ditambahkan ke akhir playlist.\n", title, artist);
}

void AddSongAfter(char *after, char *title, char *artist)
{
    struct Song *temp = head;
    while (temp != NULL && stricmp(temp->title, after) != 0)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Judul Lagu %s tidak ditemukan\n", after);
        return;
    }

    struct Song *newNode = createNode();

    strcpy(newNode->title, title);
    strcpy(newNode->artist, artist);

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    printf("Lagu \"%s\" dari Artist \"%s\" berhasil ditambahkan setelah \"%s\".\n", title, artist, after);
}

void DeleteFirstSong()
{
    if (head == NULL)
    {
        printf("Playlist kosong, tidak ada lagu yang bisa dihapus.\n");
        return;
    }

    struct Song *temp = head;

    if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }

    printf("Lagu \"%s\" dari Artist \"%s\" berhasil dihapus dari awal playlist.\n", temp->title, temp->artist);
    free(temp);
}

void SearchSong(char *songSearch, int mode)
{
    printf("\n");
    if (head == NULL)
    {
        printf("Playlist masih kosong.\n");
        return;
    }
    struct Song *temp = head;
    int position = 1;
    int found = 0;
    while (temp != NULL)
    {
        if ((mode == 1 && stricmp(temp->title, songSearch) == 0) || (mode == 2 && stricmp(temp->artist, songSearch) == 0))
        {
            printf("Lagu Ditemukan\n");
            printf("Posisi lagu ada di urutan ke-%d\n", position);
            printf("Judul Lagu  : %s\n", temp->title);
            printf("Nama Artist : %s\n", temp->artist);
            printf("-----------------------------\n");

            found = 1;
        }
        temp = temp->next;
        position++;
    }

    if (found == 0)
    {
        printf("Data \"%s\" tidak ditemukan.\n", songSearch);
    }
}

main()
{
    int choice;
    char titleSong[100], artistName[100], afterSong[100];

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
                AddLastSong(titleSong, artistName);
            }
            break;
        case 3:
            printf("Masukan Judul Lagu Setelah Lagu Apa : ");
            scanf(" %[^\n]", &afterSong);
            printf("Masukan Judul Lagu : ");
            scanf(" %[^\n]", &titleSong);
            printf("Masukan Nama Artist : ");
            scanf(" %[^\n]", &artistName);
            if (strlen(titleSong) == 0 || strlen(artistName) == 0 || strlen(afterSong) == 0)
            {
                printf("Judul Lagu/Nama Artist Tidak Boleh Kosong");
            }
            else
            {
                AddSongAfter(afterSong, titleSong, artistName);
            }

            break;
        case 4:
            DeleteFirstSong();
            break;
        case 5:
            // Hapus Lagu Dari Playlist Akhir
            break;
        case 6:
            // Tampilkan Lagu
            break;
        case 7:
            printf("Anda memilih menu untuk mencari lagu\n");
            system("pause");
            do
            {
                printf("1. Cari Berdasarkan Judul Lagu\n");
                printf("2. Cari Berdasarkan Nama Artist\n");
                printf("Pilih : ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    printf("Masukan Judul Lagu : ");
                    scanf(" %[^\n]", titleSong);
                    SearchSong(titleSong, 1);
                }
                else if (choice == 2)
                {
                    printf("Masukan Nama Artist : ");
                    scanf(" %[^\n]", artistName);
                    SearchSong(artistName, 2);
                }
                else
                {
                    printf("\nPilih antara 1-2\n");
                }
            } while (choice != 1 && choice != 2);
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
