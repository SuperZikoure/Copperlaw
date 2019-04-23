/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** manage_gui.c
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "graph.h"
#include "my_rpg.h"

cursor_t *create_cursor(game_t *game)
{
    cursor_t *cursor = malloc(sizeof(cursor_t));

    cursor->pos.x = 0;
    cursor->pos.y = 0;
    cursor->mode = 1;
    cursor->base = create_anim((sfVector2f){1, 19}, (sfVector2i){32, 32},
    "assets/cursor/base.png", game->window);
    cursor->idle = create_anim((sfVector2f){7, 19}, (sfVector2i){32, 32},
    "assets/cursor/idle.png", game->window);
    cursor->build = create_anim((sfVector2f){7, 19}, (sfVector2i){32, 32},
    "assets/cursor/build.png", game->window);
    cursor->inspect = create_anim((sfVector2f){7, 19}, (sfVector2i){32, 32},
    "assets/cursor/inspect.png", game->window);
    return (cursor);
}

void manage_cursor(game_t *game, sfVector2i pos)
{
    window_t *window = game->window;
    cursor_t *cursor = game->gui->cursor;
    view_t *view = game->view;

    cursor->pos.x = global_to_view_mouse(i_to_f(pos), view).x - 16;
    cursor->pos.y = global_to_view_mouse(i_to_f(pos), view).y - 16;
    update_anim(cursor->idle);
    update_anim(cursor->build);
    update_anim(cursor->inspect);
    sfSprite_setPosition(cursor->base->sheet->sprite, cursor->pos);
    if (cursor->mode == 0)
        cursor->display = cursor->base;
    if (cursor->mode == 1)
        cursor->display = cursor->idle;
    if (cursor->mode == 2)
        cursor->display = cursor->inspect;
    if (cursor->mode == 3)
        cursor->display = cursor->build;
    display_anim(cursor->display, cursor->pos);
}

gui_t *create_gui(view_t *view)
{
    gui_t *gui = malloc(sizeof(gui_t));

    gui->parent = view->parent;
    gui->cursor = create_cursor(view->parent);
    for (int i = 0; i < BUTTON_AMOUNT; i++) {
        gui->button[i] = create_button(info[i].path, info[i].pos,
        view, info[i].trigger);
    }
    gui->pos.x = 0;
    gui->pos.y = 0;
    gui->cursor->pos.x = 0;
    gui->cursor->pos.y = 0;
    return (gui);
}