/*
** EPITECH PROJECT, 2023
** MY_HUNTER
** File description:
** it's my main bro
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <unistd.h>
#include "my_hunter.h"

int main(void)
{
    windows *w;

    w->size_x = 1600;
    w->size_y = 900;
    sfVideoMode video_mode = {w->size_x, w->size_y, 32};
    sfRenderWindow *window = sfRenderWindow_create(video_mode, "hello",
        sfResize | sfClose, NULL);

    create_window(window, w);
}
