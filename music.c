/*
** EPITECH PROJECT, 2023
** MY_HUNTER
** File description:
** it'll display my music
*/
#include "my_hunter.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdio.h>

void my_song(music *el_music, char *my_path)
{
    el_music->music = sfMusic_createFromFile(my_path);
}

int init_my_playlist(music *el_music)
{
    int size = 2;

    el_music[size];
    my_song(&el_music[0], "canard/ignition.ogg");
    my_song(&el_music[1], "canard/the_monster.ogg");
    return size;
}

void play_only_one_music(music *el_music)
{
    sfMusic_setLoop(el_music->music, sfTrue);
    sfMusic_play(el_music->music);
}

void play_playlist(music *el_music, int i)
{
    sfMusic_play(el_music[i].music);
    if (sfMusic_getStatus(el_music[i].music) != sfPlaying)
        sfMusic_stop(el_music[i].music);
}

void destroy_music(music *el_music, int size)
{
    if (size > 1) {
        for (int i = 0; i < size; i++) {
            sfMusic_destroy(el_music[i].music);
        }
    } else {
        sfMusic_destroy(el_music->music);
    }
}
