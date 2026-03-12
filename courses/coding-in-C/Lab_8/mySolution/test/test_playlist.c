#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../include/playlist.h"

/* === Unit-tests === */

// example unit test
void test_init_playlist(void)
{
    Playlist *p = init_playlist();

    assert(p->first_song == NULL);

    // Free memory
    delete_playlist(&p);
}

// Test adding songs
void test_add_song(void)
{
    Playlist *p = init_playlist();

    assert(add_song("test song", "test artist", p) == 1);
    assert(strcmp(p->first_song->title, "test song") == 0);
    assert(strcmp(p->first_song->artist, "test artist") == 0);

    assert(add_song("song2", "artist2", p));
    assert(strcmp(p->first_song->next_song->title, "song2") == 0);
    assert(strcmp(p->first_song->next_song->artist, "artist2") == 0);

    // Free memory
    delete_playlist(&p);
}

// Test deleting first song
void test_delete_firstSong(void)
{
    Playlist *p = init_playlist();
    assert(add_song("title", "artist", p) == 1);  // also test if add_song worked

    assert(delete_firstSong(p) == 1);
    assert(p->first_song == NULL);

    // Free memory
    delete_playlist(&p);
}

void test_delete_firstSong_empty(void)
{
    Playlist *p = init_playlist();

    assert(delete_firstSong(p) == 0);

    // Free memory
    delete_playlist(&p);
}

// Test deleting entire playlist
void test_delete_playlist(void)
{
    Playlist *p = init_playlist();
    // Fill playlist with 10 dummy songs
    for(int i = 0; i < 10; i++)
    {
        assert(add_song("dummy", "dummy", p) == 1);
    }

    assert(delete_playlist(&p) == 1);
    assert(p == NULL);
    
    // Case of empty playlist
    p = init_playlist();

    assert(delete_playlist(&p) == 0);
    assert(p == NULL);
}

// Test max song limit
void test_max_songs_limit(void)
{
    Playlist *p = init_playlist();
    // Fill playlist with MAX_SONGS songs
    for(int i = 0; i < MAX_SONGS; i++)
    {
        assert(add_song("dummy", "dummy", p) == 1);
    }

    assert(add_song("dummy", "dummy", p) == 0); // One song too much

    // Free memory
    delete_playlist(&p);
}

// Test playlist length function
void test_get_playlist_length(void)
{
    Playlist *p = init_playlist();
    
    assert(get_playlist_length(p) == 0);

    for(int i = 0; i < MAX_SONGS; i++)
    {
        assert(add_song("dummy", "dummy", p) == 1);
        
        assert(get_playlist_length(p) == i+1);
    }

    // Free memory
    delete_playlist(&p);
}

/* === Test-Runner === */

int main(void)
{
    test_init_playlist();
    test_add_song();
    test_delete_firstSong();
    test_delete_firstSong_empty(); // what happens if we delete first song from empty playlist
    test_delete_playlist();
    test_max_songs_limit(); // verify if the limit will be not be surpassed
    test_get_playlist_length();

    printf("Alle Playlist-Tests erfolgreich bestanden.\n");
    return 0;
}
