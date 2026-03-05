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
    const char *songs[] = {"Daydreamers", "Song 2", "Stick Up", "Moonshine"};
    const char *artists[] = {"AURORA", "Blur", "Grandson", "Caravan Palace"};

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

    // 6. Delete complete playlist and free memory for playlist
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
    Playlist *new_playlist = malloc(sizeof *new_playlist);
    if(!new_playlist)
    {
        printf("Error allocating memory for playlist!\n");
        return NULL;
    }
    new_playlist->first_song = NULL;
    return new_playlist;
}

/**
 * @brief Adds a new song to the end of the playlist
 * 
 * @param[in] title title of the song (string)
 * @param[in] artist artist of the song (string)
 * @param[out] playlist playlist to add the song to
 * 
 * @return success: 1; fail: 0
 */
int add_song(const char *title, const char *artist, Playlist *playlist)
{
    // Allocate memory for strings
    char *ptr_title = malloc((sizeof(char)) * (strlen(title) + 1));
    if(!ptr_title)
    {
        printf("Error allocating memory for title string!\n");
        return 0;
    }
    char *ptr_artist = malloc((sizeof(char)) * (strlen(artist) + 1));
    if(!ptr_artist)
    {
        printf("Error allocating memory for artist string!\n");
        free(ptr_title);
        return 0;
    }
    // Allocate memory for song struct
    Song *new_song = malloc(sizeof *new_song);
    if(!new_song)
    {
        printf("Error allocating memory for song struct!\n");
        free(ptr_title);
        free(ptr_artist);
        return 0;
    }
    // Write title and artist to new variables in heap
    strcpy(ptr_title, title);
    strcpy(ptr_artist, artist);
    // Save title and artist in new_song
    new_song->title = ptr_title;
    new_song->artist = ptr_artist;
    new_song->next_song = NULL;

    // Add new_song to playlist
    if(playlist->first_song == NULL)
    {
        // Playlist is empty -> replace first song
        playlist->first_song = new_song;
        return 1;
    }
    // Playlist contains at least one element -> iterate to the last one, append new song there
    Song *iterator = playlist->first_song;
    while(iterator->next_song != NULL)
    {
        iterator = iterator->next_song;
    }
    iterator->next_song = new_song;

    return 1;
}

/**
 * @brief prints the entire playlist in a given format
 * 
 * @param[in] playlist playlist to be printed
 */
void print_playlist(Playlist *playlist)
{
    if(playlist->first_song == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }
    Song *iterator = playlist->first_song;
    while(iterator != NULL)
    {
        printf("Title: %s, Artist: %s\n", iterator->title, iterator->artist);
        iterator = iterator->next_song;
    }
    printf("\n");
}

/**
 * @brief Removes the first song from the playlist and frees all allocatet memory
 * 
 * @param[out] playlist playlist of which the first song should be removed
 * 
 * @return returns 0 if playlist is empty, else: 1
 */
int delete_firstSong(Playlist *playlist)
{
    if(playlist->first_song == NULL)
    {
        // Playlist is empty
        printf("Failed to remove first song. Playlist is empty!\n");
        return 0;
    }
    // Remember first song
    Song *first_song = playlist->first_song;
    // Remove first song from linked list
    playlist->first_song = first_song->next_song;

    // Free all memory for first song
    free(first_song->artist);
    free(first_song->title);
    free(first_song);

    return 1;
}

/**
 * @brief Remove all songs from the playlist and free all allocated memory
 * 
 * @param[out] playlist playlist to delete -> will become empty playlist
 * 
 * @return 0 if playlist already empty, else: 1
 */
int delete_playlist(Playlist *playlist)
{
    if(playlist->first_song == NULL)
    {
        printf("Playlist is already empty!\n");
        free(playlist);
        return 0;
    }

    // Remove first song of playlist as long as there are songs in the playlist
    while(playlist->first_song != NULL)
    {
        delete_firstSong(playlist);
    }

    free(playlist);
    return 1;
}