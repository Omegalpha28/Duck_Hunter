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

void analyse_events_game(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        close_event(window, event);
    }
}

void in_game(sfRenderWindow *window, sfSprite *sprite, sfMusic *music)
{
    sfMusic_play(music);
    while (sfRenderWindow_isOpen(window)) {
        analyse_events_game(window);
        sfRenderWindow_display(window);
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_close(window);
    sfMusic_stop(music);
    sfMusic_destroy(music);
}

void play_game(sfRenderWindow *window)
{
    landscape land;

    land.texture = sfTexture_createFromFile("canard/fond_ecran.jpg", NULL);
    land.sprite = sfSprite_create();
    sfSprite_setTexture(land.sprite, land.texture, sfTrue);
    sfMusic* music = sfMusic_createFromFile("canard/ignition.ogg");

    in_game(window, land.sprite, music);
}