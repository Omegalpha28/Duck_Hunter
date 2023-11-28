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
    printf("ok\n");
    sfRenderWindow_drawSprite(window, sprite->sprite, NULL);
}

void tot_size_sprite(sprite *sprite, int tot_size_x, int tot_size_y)
{
    sprite->tot_size_x = tot_size_x;
    sprite->tot_size_y = tot_size_y;
}

void init_score(sprite *score)
{
    sfVector2f newSpritePosition = {1800.0f, 10.0f};

    my_sprite(score, "canard/number.png", 101, 103);
    animation(score);
    sfSprite_setPosition(score->sprite, newSpritePosition);
}
