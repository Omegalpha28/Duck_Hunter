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

void manage_mouse_click(sfMouseButtonEvent mouse)
{
    
}

void analyse_events(sfRenderWindow  *window,
    sfEvent event, sfMouseButtonEvent mouse)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed)
            manage_mouse_click(mouse);
    }
}

void create_window(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920, 1080, 32};
    sfEvent event;
    sfMouseButtonEvent mouse;

    window = sfRenderWindow_create(video_mode, "...", sfDefaultStyle, NULL);
    while (sfRenderWindow_isOpen(window)) {
        analyse_events(window, event, mouse);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_close(window);
    return 0;
}
