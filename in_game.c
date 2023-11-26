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

void my_sprite(sprite *sprite, char *path, int size_x, int size_y)
{
    sprite->size_x = size_x;
    sprite->size_y = size_y;
    sprite->texture = sfTexture_createFromFile(path, NULL);
    sprite->sprite = sfSprite_create();
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
}

void create_crosshair(sprite *crosshair)
{
    sfVector2f scale = {0.1, 0.1};

    my_sprite(crosshair, "canard/crosshair.png", 1200, 1200);
    tot_size_sprite(crosshair, 1200, 1200);
    sfSprite_setScale(crosshair->sprite, scale);
}

void mouse_pos_cible(sfRenderWindow *window, music *music,
    sprite *crosshair)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(window);
    sfVector2f newSpritePosition = {(float)mpos.x, (float)mpos.y};

    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_setPosition(crosshair->sprite, newSpritePosition);
}

void analyse_events_game(sfRenderWindow *window, music *music,
    sprite *crosshair)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        close_event(window, event);
        mouse_pos_cible(window, music, crosshair);
    }
}

void in_game(sfRenderWindow *window, sprite *background_game, sprite *duck,
    sprite *crosshair)
{
    music *music;
    int size = init_my_playlist(music);
    int i = 0;

    play_playlist(music, i);
    while (sfRenderWindow_isOpen(window)) {
        analyse_events_game(window, music, crosshair);
        display_sprite(window, background_game);
        display_sprite(window, duck);
        display_sprite(window, crosshair);
        sfRenderWindow_display(window);
        if (sfMusic_getStatus(music[i].music) != sfPlaying && i < size) {
            i++;
            play_playlist(music, i);
        }
        if (sfMusic_getStatus(music[i].music) != sfPlaying && i == size){
            i = 0;
            play_playlist(music, i);
        }
    }
    destroy_music(music, size);
}
