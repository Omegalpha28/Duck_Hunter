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
#include "my_hunter.h"
#include <stdio.h>

void display_sprite(sfRenderWindow *window, sprite *sprite)
{
    sfRenderWindow_drawSprite(window, sprite->sprite, NULL);
}

void tot_size_sprite(sprite *sprite, int tot_size_x, int tot_size_y)
{
    sprite->tot_size_x = tot_size_x;
    sprite->tot_size_y = tot_size_y;
}
