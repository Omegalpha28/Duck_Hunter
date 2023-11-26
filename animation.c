#include "my_hunter.h"

void animation(landscape *sprite)
{
    sprite->rect_source_sprite = (sfIntRect){0, 0, sprite->size_x,
        sprite->size_y};
    sfSprite_setTextureRect(sprite->sprite, sprite->rect_source_sprite);
}

void playing_animation(landscape *sprite)
{
    sprite->rect_source_sprite.left += sprite->size_x;
    if (sprite->rect_source_sprite.left > sprite->tot_size_x) {
        sprite->rect_source_sprite.left = 0;
    }
    sfSprite_setTextureRect(sprite->sprite, sprite->rect_source_sprite);
}