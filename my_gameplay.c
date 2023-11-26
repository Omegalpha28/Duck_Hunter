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

void my_gameplay(sfRenderWindow *window)
{
    sprite background_game;
    sprite duck;
    sprite crosshair;

    create_crosshair(&crosshair);
    my_sprite(&background_game, "canard/fond_ecran_game.jpg", 1920, 899);
    my_sprite(&duck, "canard/coin_coin.png", 110, 110);
    sfSprite_setScale(background_game.sprite, (sfVector2f){1.1, 1.28});
    tot_size_sprite(&background_game, 1920, 899);
    tot_size_sprite(&duck, 331, 110);
    in_game(window, &background_game, &duck, &crosshair);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_close(window);
}
