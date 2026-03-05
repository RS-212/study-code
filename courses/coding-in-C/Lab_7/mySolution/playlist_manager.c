/**
 * @file playlist_manager.c
 * 
 * @brief Simple music playlist manager in C using structs, pointers, dynamic memory allocation, and linked lists
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structs
typedef struct Song
{
    char *title;
    char *artist;
    struct Song *next_song;
} Song;

typedef struct
{
    Song *first_song;
} Playlist;

// Function prototypes
Playlist *init_playlist();
int add_song(const char *title, const char *artist, Playlist *playlist);
void print_playlist(Playlist *playlist);
int delete_firstSong(Playlist *playlist);
int delete_playlist(Playlist *playlist);

int main()
{
    const char songs[] = {"Daydreamers", "Song 2", "Stick Up", "Moonshine"};
    const char artists[] = {"AURORA", "Blur", "Grandson", "Caravan Palace"};

    // 1. Create and initialize a playlist
    Playlist *my_playlist = init_playlist();

    // 2. Add songs to playlist
    for(int i = 0; i < 4; i++)
    {
        if(!add_song(songs[i], artists[i], my_playlist))
        {
            printf("Error adding song. Exiting!\n");
            delete_playlist(my_playlist);
            return 1;
        }
    }

    // 3. Print the playlist
    print_playlist(my_playlist);

    // 4. Delete the first song
    delete_firstSong(my_playlist);

    // 5. Print playlist again
    print_playlist(my_playlist);

    // 6. Delete complete playlist
    delete_playlist(my_playlist);

    return 0;
}

/**
 * @brief Initializes an empty playlist
 * 
 * @return pointer to the new playlist
 */
Playlist *init_playlist()
{

}