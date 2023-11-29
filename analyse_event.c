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

void mouse_pos(sfRenderWindow *window, music *music)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(window);

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (mpos.x <= 990 && mpos.x >= 815 && mpos.y <= 775 && mpos.y >= 700) {
            sfMusic_stop(music->music);
            sfMusic_destroy(music->music);
            my_gameplay(window);
        }
    }
}

void close_event(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
    }
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

void sprite_size(sfSprite *sprite, sfVector2f scale, sfVector2f pos)
{
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
}

void analyse_event(sfRenderWindow *window, music *m)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        close_event(window, event);
        mouse_pos(window, m);
    }
}
