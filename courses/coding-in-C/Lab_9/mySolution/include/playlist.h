#ifndef PLAYLIST_H
#define PLAYLIST_H

#define MAX_SONGS 100

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
int delete_playlist(Playlist **playlist);
int get_playlist_length(Playlist *playlist);

#endif