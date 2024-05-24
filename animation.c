/*
** EPITECH PROJECT, 2023
** MY_HUNTER
** File description:
** the filename say everything
*/
#include "my_hunter.h"
#include <stdlib.h>

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

void playing_tab_animation(sprite *sprite)
{
    sprite->rect_source_sprite.left += sprite->size_x;
    if (sprite->rect_source_sprite.left > sprite->tot_size_x) {
        sprite->rect_source_sprite.left = 0;
        sprite->rect_source_sprite.top += sprite->size_y;
    }
    sfSprite_setTextureRect(sprite->sprite, sprite->rect_source_sprite);
}

void new_scale(sprite *crosshair)
{
    sfVector2f scale = {0.18, 0.18};

    sfSprite_setScale(crosshair->sprite, scale);
}

void running_sprite(sfRenderWindow *window, sprite *my_sprite, sprite *cross)
{
    sfVector2i mposi = sfMouse_getPositionRenderWindow(window);
    sfVector2f mpos = sfSprite_getPosition(my_sprite->sprite);
    sfVector2f newSpritePosition = {(float)mpos.x, (float)mpos.y};

    mpos.x += 0.6;
    if (mpos.x >= 1920) {
        mpos.x = 0;
        mpos.y = 0 + rand() % (900 + 1 - 0);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (mposi.x <= (mpos.x + 55) && mposi.x >= (mpos.y - 55)
            && mposi.y <= (mpos.y + 55) && mposi.y >= (mpos.y - 75)){
            mpos.x = 0;
            mpos.y = 0 + rand() % (900 + 1 - 0);
        }
    }
    newSpritePosition = (sfVector2f){(float)mpos.x, (float)mpos.y};
    sfSprite_setPosition(my_sprite->sprite, newSpritePosition);
}
