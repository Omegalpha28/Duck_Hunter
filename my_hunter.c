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

void main_menu(sfRenderWindow *window)
{
    music m;
    sprite background;

    background.texture = NULL;
    background.sprite = NULL;
    sprite_menu(window, &background);
    my_song(&m, "canard/the_monster.ogg");
    play_only_one_music(&m);
    while (sfRenderWindow_isOpen(window)) {
        analyse_event(window, &m);
        sfRenderWindow_display(window);
        sfRenderWindow_drawSprite(window, background.sprite, NULL);
    }
    end_of_the_window(window, &m);
}

int main(int ac, char **av)
{
    windows *w;
    sfVideoMode video_mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(video_mode, "MY HUNTER",
        sfResize | sfClose , NULL);

    if (ac > 1) {
        write(2, "Too arguments!!", 16);
        return 84;
    }
    main_menu(window);
    return 0;
}
