/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** manage_gui.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "graph.h"
#include "my_rpg.h"
#include "my_string.h"
#include "macros.h"

static cursor_t *create_cursor(game_t *game)
{
    cursor_t *cursor = malloc(sizeof(cursor_t));

    if (!cursor)
        return NULL;
    cursor->pos.x = 0;
    cursor->pos.y = 0;
    cursor->mode = 0;
    cursor->base = create_anim(V2F(1, 19), V2I(32, 32),
"assets/cursor/base.png", game->window);
    cursor->idle = create_anim(V2F(7, 19), V2I(32, 32),
"assets/cursor/idle.png", game->window);
    cursor->build = create_anim(V2F(7, 19), V2I(32, 32),
"assets/cursor/build.png", game->window);
    cursor->inspect = create_anim(V2F(7, 19), V2I(32, 32),
"assets/cursor/inspect.png", game->window);
    if (!cursor->base || !cursor->idle || !cursor->build || !cursor->inspect)
        return NULL;
    return (cursor);
}

gui_t *create_gui(view_t *view)
{
    gui_t *gui = malloc(sizeof(gui_t));

    if (!gui)
        return NULL;
    gui->parent = view->parent;
    gui->cursor = create_cursor(view->parent);
    if (!gui->cursor)
        return NULL;
    for (int i = 0; i < BUTTON_AMOUNT; i++) {
        gui->button[i] = create_button(info[i].path, info[i].pos,
view, info[i].trigger);
    }
    return (gui);
}
