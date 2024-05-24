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

void end_of_the_window(sfRenderWindow *window, music *music)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_close(window);
    sfMusic_stop(music->music);
    sfMusic_destroy(music->music);
}

void my_sprite_display(sfRenderWindow *window, sprite *sprite, char *my_path)
{
    sprite->texture = sfTexture_createFromFile(my_path, NULL);
    sprite->sprite = sfSprite_create();
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
}

void sprite_menu(sfRenderWindow *window, sprite *background)
{
    background->texture = sfTexture_createFromFile("canard/menu_b.png", NULL);
    background->sprite = sfSprite_create();
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    sfSprite_setScale(background->sprite, (sfVector2f){1.25, 1.28});
}
