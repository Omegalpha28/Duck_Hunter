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
    display_sprite(window, background_game);
    display_sprite(window, duck);
    display_sprite(window, crosshair);
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

void my_display_score(sfRenderWindow *window, sprite *score, sprite *duck)
{
    sfVector2f mpos = sfSprite_getPosition(duck->sprite);

    display_sprite(window, score);
    sfSprite_setScale(score->sprite, (sfVector2f){1.0, 0.9});
    tot_size_sprite(score, 518, 206);
    if (mpos.x > 1920){
        playing_tab_animation(score);
    }
}

void scale_origins(sprite *sprite)
{
    sfVector2f origins = {0.1, 0.1};

    sfSprite_setScale(sprite->sprite, origins);
}
