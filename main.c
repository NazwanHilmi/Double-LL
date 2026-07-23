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
struct Song *currentSong = NULL; // Menyimpan lagu yang sedang diputar

struct Song *createNode()
{
    struct Song *newNode = (struct Song *)malloc(sizeof(struct Song));
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// 1. Tambah Lagu Ke Playlist Awal
void AddFirstSong(char *title, char *artist)
{
    struct Song *newNode = createNode();

    strcpy(newNode->title, title);
    strcpy(newNode->artist, artist);

    if (head == NULL)
    {
        head = newNode;
        currentSong = head; // Lagu pertama otomatis jadi lagu yang sedang diputar
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    printf("\nLagu \"%s\" dari Artist \"%s\" berhasil ditambahkan di awal playlist.\n", title, artist);
}

// 2. Tambah Lagu Ke Playlist Akhir
void AddLastSong(char *title, char *artist)
{
    struct Song *newNode = createNode();
    strcpy(newNode->title, title);
    strcpy(newNode->artist, artist);

    if (head == NULL)
    {
        head = newNode;
        currentSong = head;
    }
    else
    {
        struct Song *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("\nLagu \"%s\" dari Artist \"%s\" berhasil ditambahkan di akhir playlist.\n", title, artist);
}

// 3. Tambah Lagu Setelah Lagu Tertentu
void AddAfterSong(char *targetTitle, char *title, char *artist)
{
    if (head == NULL)
    {
        printf("\nPlaylist kosong, tidak bisa menambah setelah lagu tertentu.\n");
        return;
    }

    struct Song *temp = head;
    while (temp != NULL && strcmpi(temp->title, targetTitle) != 0)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\nLagu \"%s\" tidak ditemukan di playlist.\n", targetTitle);
    }
    else
    {
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

        printf("\nLagu \"%s\" berhasil ditambahkan setelah lagu \"%s\".\n", title, targetTitle);
    }
}

// 4. Hapus Lagu Dari Playlist Awal
void DeleteFirstSong()
{
    if (head == NULL)
    {
        printf("\nPlaylist kosong, tidak ada lagu yang bisa dihapus.\n");
        return;
    }

    struct Song *temp = head;

    // Jika lagu yang dihapus sedang diputar
    if (currentSong == temp)
    {
        currentSong = head->next;
    }

    if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }

    printf("\nLagu \"%s\" dari Artist \"%s\" berhasil dihapus dari awal playlist.\n", temp->title, temp->artist);
    free(temp);
}

// 5. Hapus Lagu Dari Playlist Akhir
void DeleteLastSong()
{
    if (head == NULL)
    {
        printf("\nPlaylist kosong, tidak ada lagu yang bisa dihapus.\n");
        return;
    }

    struct Song *temp = head;

    if (head->next == NULL)
    {
        if (currentSong == head)
        {
            currentSong = NULL;
        }
        head = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        if (currentSong == temp)
        {
            currentSong = temp->prev;
        }

        temp->prev->next = NULL;
    }

    printf("\nLagu \"%s\" dari Artist \"%s\" berhasil dihapus dari akhir playlist.\n", temp->title, temp->artist);
    free(temp);
}

// 6. Tampilkan Seluruh Lagu
void DisplayPlaylist()
{
    if (head == NULL)
    {
        printf("\nPlaylist masih kosong.\n");
        return;
    }

    struct Song *temp = head;
    int no = 1;

    printf("\n=== DAFTAR PLAYLIST ===\n");
    while (temp != NULL)
    {
        if (temp == currentSong)
        {
            printf("%d. %s - %s [Sedang Diputar]\n", no, temp->title, temp->artist);
        }
        else
        {
            printf("%d. %s - %s\n", no, temp->title, temp->artist);
        }
        temp = temp->next;
        no++;
    }
    printf("=======================\n");
}

// 7. Cari Lagu Berdasarkan Artist/Judul
void SearchSong(char *query)
{
    if (head == NULL)
    {
        printf("\nPlaylist kosong.\n");
        return;
    }

    struct Song *temp = head;
    int found = 0;
    int no = 1;

    printf("\n=== HASIL PENCARIAN ===\n");
    while (temp != NULL)
    {
        if (strstr(temp->title, query) != NULL || strstr(temp->artist, query) != NULL)
        {
            printf("%d. Judul: %s | Artist: %s\n", no, temp->title, temp->artist);
            found = 1;
        }
        temp = temp->next;
        no++;
    }

    if (!found)
    {
        printf("Lagu/Artist dengan kata kunci \"%s\" tidak ditemukan.\n", query);
    }
    printf("=======================\n");
}

// 8. Mainkan Lagu Selanjutnya
void PlayNextSong()
{
    if (currentSong == NULL)
    {
        printf("\nPlaylist kosong atau belum ada lagu diputar.\n");
    }
    else if (currentSong->next == NULL)
    {
        printf("\nIni sudah merupakan lagu terakhir di playlist.\n");
    }
    else
    {
        currentSong = currentSong->next;
        printf("\nMemutar lagu selanjutnya: \"%s\" - %s\n", currentSong->title, currentSong->artist);
    }
}

// 9. Mainkan Lagu Sebelumnya
void PlayPrevSong()
{
    if (currentSong == NULL)
    {
        printf("\nPlaylist kosong atau belum ada lagu diputar.\n");
    }
    else if (currentSong->prev == NULL)
    {
        printf("\nIni sudah merupakan lagu pertama di playlist.\n");
    }
    else
    {
        currentSong = currentSong->prev;
        printf("\nMemutar lagu sebelumnya: \"%s\" - %s\n", currentSong->title, currentSong->artist);
    }
}

// 10. Tampilkan Lagu Yang Sedang Diputar
void DisplayCurrentSong()
{
    if (currentSong == NULL)
    {
        printf("\nTidak ada lagu yang sedang diputar.\n");
    }
    else
    {
        printf("\n=== SEDANG DIPUTAR ===\n");
        printf("Judul  : %s\n", currentSong->title);
        printf("Artist : %s\n", currentSong->artist);
        printf("======================\n");
    }
}

int main()
{
    int choice;
    char titleSong[100], artistName[100], targetTitle[100], searchQuery[100];

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
            scanf(" %[^\n]", titleSong);
            printf("Masukan Nama Artist : ");
            scanf(" %[^\n]", artistName);
            if (strlen(titleSong) == 0 || strlen(artistName) == 0)
            {
                printf("Judul Lagu/Nama Artist Tidak Boleh Kosong\n");
            }
            else
            {
                AddFirstSong(titleSong, artistName);
            }
            break;

        case 2:
            printf("Masukan Judul Lagu : ");
            scanf(" %[^\n]", titleSong);
            printf("Masukan Nama Artist : ");
            scanf(" %[^\n]", artistName);
            if (strlen(titleSong) == 0 || strlen(artistName) == 0)
            {
                printf("Judul Lagu/Nama Artist Tidak Boleh Kosong\n");
            }
            else
            {
                AddLastSong(titleSong, artistName);
            }
            break;

        case 3:
            printf("Masukan Judul Lagu Acuan : ");
            scanf(" %[^\n]", targetTitle);
            printf("Masukan Judul Lagu Baru : ");
            scanf(" %[^\n]", titleSong);
            printf("Masukan Nama Artist Baru : ");
            scanf(" %[^\n]", artistName);
            AddAfterSong(targetTitle, titleSong, artistName);
            break;

        case 4:
            DeleteFirstSong();
            break;

        case 5:
            DeleteLastSong();
            break;

        case 6:
            DisplayPlaylist();
            break;

        case 7:
            printf("Masukan Judul/Artist yang Dicari : ");
            scanf(" %[^\n]", searchQuery);
            SearchSong(searchQuery);
            break;

        case 8:
            PlayNextSong();
            break;

        case 9:
            PlayPrevSong();
            break;

        case 10:
            DisplayCurrentSong();
            break;

        case 0:
            printf("\nKeluar dari program. Terima kasih!\n");
            break;

        default:
            printf("\nPilihan tidak valid.\n");
            break;
        }

        if (choice != 0)
        {
            printf("\n");
            system("pause");
        }
    } while (choice != 0);

    return 0;
}
