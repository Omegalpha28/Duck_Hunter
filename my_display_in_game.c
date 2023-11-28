/*
** EPITECH PROJECT, 2023
** MY_HUNTER
** File description:
** these function will create and display the window
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <unistd.h>
#include "my_hunter.h"
#include <stdio.h>

void my_display_in_game(sfRenderWindow *window, sprite *duck,
    sprite *background_game, sprite *crosshair)
{
    playing_animation(duck);
    printf("duck\n");
    display_sprite(window, background_game);
    printf("background\n");
    display_sprite(window, duck);
    printf("duck2\n");
    display_sprite(window, crosshair);
    printf("crosshair\n");
}

int verif_music_game(music *music, int i, int size)
{
    if (sfMusic_getStatus(music[i].music) != sfPlaying && i < size) {
        i++;
        play_playlist(music, i);
    }
    if (sfMusic_getStatus(music[i].music) != sfPlaying && i == size){
        i = 0;
        play_playlist(music, i);
    }
    return i;
}

void my_display_score(sfRenderWindow *window, sprite *score)
{
    display_sprite(window, score);
    sfSprite_setScale(score->sprite, (sfVector2f){1.0, 0.9});
    tot_size_sprite(score, 518, 206);
}
