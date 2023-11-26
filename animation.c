/*
** EPITECH PROJECT, 2023
** MY_HUNTER
** File description:
** the filename say everything
*/
#include "my_hunter.h"

void animation(sprite *sprite)
{
    sprite->rect_source_sprite = (sfIntRect){0, 0, sprite->size_x,
        sprite->size_y};
    sfSprite_setTextureRect(sprite->sprite, sprite->rect_source_sprite);
}

void playing_animation(sprite *sprite)
{
    sprite->rect_source_sprite.left += sprite->size_x;
    if (sprite->rect_source_sprite.left > sprite->tot_size_x) {
        sprite->rect_source_sprite.left = 0;
    }
    sfSprite_setTextureRect(sprite->sprite, sprite->rect_source_sprite);
}
