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

void close_event(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

void my_playlist(sfRenderWindow *window)
{
    sfMusic* music = sfMusic_createFromFile("canard/ignition.mp3");
    sfMusic_play(music);
}

void mouse_pos(sfRenderWindow *window, sfMusic *music)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(window);

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        printf("Clic de la souris à la position : (%d, %d)\n", mpos.x, mpos.y);
        if (mpos.x <= 946 && mpos.x >= 675 && mpos.y <= 580 && mpos.y >= 465) {
            printf("Dans la zone bg");
            sfMusic_stop(music);
            sfMusic_destroy(music);
            play_game(window);
        }
    }

}

void analyse_events(sfRenderWindow *window, sfMusic *music)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        close_event(window, event);
        mouse_pos(window, music);
    }
}

void game(sfRenderWindow *window, sfSprite *sprite,
    sfSprite *sec_sprite, sfMusic *music)
{
    sfMusic_play(music);
    while (sfRenderWindow_isOpen(window)) {
        analyse_events(window, music);
        sfRenderWindow_display(window);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, sec_sprite, NULL);
    }
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_close(window);
    sfMusic_stop(music);
    sfMusic_destroy(music);
}

void size_sprite(sfSprite *sprite, sfVector2f scale, sfVector2f pos)
{
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
}

void create_window(sfRenderWindow *window, windows *w)
{
    landscape land;
    landscape start;

    land.texture = sfTexture_createFromFile("canard/fond_ecran.jpg", NULL);
    land.sprite = sfSprite_create();
    start.texture = sfTexture_createFromFile("canard/start.png", NULL);
    start.sprite = sfSprite_create();
    sfSprite_setTexture(land.sprite, land.texture, sfTrue);
    sfSprite_setTexture(start.sprite, start.texture, sfTrue);
    size_sprite(start.sprite, (sfVector2f){0.4, 0.4},
        (sfVector2f){w->size_x / 2 - 150, w->size_y / 2});
    sfMusic* music = sfMusic_createFromFile("canard/the_monster.ogg");

    game(window, land.sprite, start.sprite, music);
}
