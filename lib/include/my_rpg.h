/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** my_rpg.h
*/

#ifndef MY_RPG_H_
#define MY_RPG_H

#include "graph.h"

#define VIEW_SIZE_X 480
#define VIEW_SIZE_Y 270
#define GLOBAL_ZOOM 1
#define WINDOW_SIZE_X 1280
#define WINDOW_SIZE_Y 720

#define BUTTON_AMOUNT 0

enum enum_scene_e {
    MENU,
    CREATE,
    LOAD,
    HELP,
    OPTIONS,
    GAME
};

typedef struct button_s
{
    void (*trigger)(game_t*);
    image_t *base;
    image_t *hover;
    image_t *click;
    image_t *display;
    sound_t *hover_sound;
    sound_t *click_sound;
    sfVector2f pos;
    sfVector2f display_pos;
    int scene;
    int mouse_hover;
    int mouse_click;
    void* parent;
} button_t;

typedef struct cursor_s
{
    sfVector2f pos;
    anim_t *base;
    anim_t *idle;
    anim_t *inspect;
    anim_t *build;
    anim_t *display;
    int mode;
    void *parent;
} cursor_t;

typedef struct gui_s {
    cursor_t *cursor;
    button_t *button[BUTTON_AMOUNT];
    sfVector2i pos;
    void *parent;
} gui_t;

typedef struct view_s {
    window_t *window;
    sfView *camera;
    sfFloatRect pos;
    sfVector2f size;
    sfVector2f offset;
    sfVector2f velocity;
    void *parent;
} view_t;

typedef struct my_clock_s {
    sfClock *clock;
    sfTime time;
    int frames;
    void *parent;
} my_clock_t;

typedef struct game_s {
    window_t *window;
    my_clock_t *clock;
    view_t *view;
    gui_t *gui;
    input_t *input;
    int exit;
    int scene;
} game_t;

/*
game->window = create_frame(WINDOW_SIZE_X, WINDOW_SIZE_Y, "Window");
    game->input = create_input();
    game->view = create_view((sfVector2f){0, 0}, 15, GLOBAL_ZOOM);
    game->interface = create_gui(game->view);
    game->exit = 0;
    game->scene = MENU;
    game->clock = create_clock();
    game->data = create_data();
    game->win = 0;
    */

#endif