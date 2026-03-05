/**
 * @file playlist.c
 * 
 * @brief Simple music playlist manager in C using structs, pointers, dynamic memory allocation, and linked lists
 */
#include "../include/playlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    // Check for song limit
    if(get_playlist_length(playlist) >= MAX_SONGS)
    {
        printf("Cannot add song, limit reached!\n");
        return 0;
    }

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

/**
 * @brief get number of songs stored in the playlist
 * 
 * @param[in] playlist playlist to count content of
 * 
 * @return number of songs (int)
 */
int get_playlist_length(Playlist *playlist)
{
    if(playlist->first_song == NULL)
    {
        return 0;
    }

    Song *iterator = playlist->first_song;
    int count = 0;
    while (iterator != NULL)
    {
        iterator = iterator->next_song;
        count++;
    }
    return count;
}