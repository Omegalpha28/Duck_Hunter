/*
** EPITECH PROJECT, 2023
** MY_HUNTER
** File description:
** header for my_hunter
*/

#ifndef MY_HUNTER_
    #define MY_HUNTER_
    #define INCLUDE
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
typedef struct {
    int x;
    int y;
}windows;
typedef struct {
    char *name;
    char *my_path;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    int size_x;
    int size_y;
    int tot_size_x;
    int tot_size_y;
    sfIntRect rect_source_sprite;
}sprite;
typedef struct {
    sfMusic *music;
}music;
int init_my_playlist(music *el_music);
void mouse_pos(sfRenderWindow *window, music *music);
void analyse_event(sfRenderWindow *window, music *m);
void destroy_music(music *el_music, int size);
void close_event(sfRenderWindow *window, sfEvent event);
void play_playlist(music *el_music, int i);
void play_only_one_music(music *el_music);
void sprite_size(sfSprite *sprite, sfVector2f scale, sfVector2f pos);
void main_menu(sfRenderWindow *window);
void sprite_menu(sfRenderWindow *window, sprite *background);
void my_display_in_game(sfRenderWindow *window, sprite *duck,
    sprite *background_game, sprite *crosshair);
void my_song(music *el_music, char *my_path);
void end_of_the_window(sfRenderWindow *window, music *music);
void my_sprite_display(sfRenderWindow *window, sprite *sprite, char *my_path);
void my_gameplay(sfRenderWindow *window);
void in_game(sfRenderWindow *window, sprite *land, sprite *duck,
    sprite *crosshair);
void analyse_events_game(sfRenderWindow *window, music *music,
    sprite *crosshair);
void my_display_score(sfRenderWindow *window, sprite *score);
void mouse_pos_cible(sfRenderWindow *window, music *music,
    sprite *crosshair);
void create_crosshair(sprite *crosshair);
void running_sprite(sfRenderWindow *window, sprite *my_sprite, sprite *cross);
void my_sprite(sprite *sprite, char *path, int size_x, int size_y);
void tot_size_sprite(sprite *sprite, int tot_size_x, int tot_size_y);
void display_sprite(sfRenderWindow *window, sprite *sprite);
void playing_animation(sprite *sprite);
int verif_music_game(music *music, int i, int size);
void animation(sprite *sprite);
void init_score(sprite *score);
void scale_origins(sprite *sprite);
#endif
