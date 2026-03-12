#include "../include/playlist.h"
#include <stdio.h>

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
            delete_playlist(&my_playlist);
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
    delete_playlist(&my_playlist);

    return 0;
}