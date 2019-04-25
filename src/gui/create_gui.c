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

    cursor->pos.x = 0;
    cursor->pos.y = 0;
    cursor->mode = 1;
    cursor->base = create_anim(V2F(1, 19), V2I(32, 32),
"assets/cursor/base.png", game->window);
    cursor->idle = create_anim(V2F(7, 19), V2I(32, 32),
"assets/cursor/idle.png", game->window);
    cursor->build = create_anim(V2F(7, 19), V2I(32, 32),
"assets/cursor/build.png", game->window);
    cursor->inspect = create_anim(V2F(7, 19), V2I(32, 32),
"assets/cursor/inspect.png", game->window);
    return (cursor);
}

static button_t *create_button(char *path, sfVector3f pos, view_t *view,
                                void (*trigger)(game_t *))
{
    button_t *button = malloc(sizeof(button_t));

    button->base = create_image(my_strcat_no_free(BUTTON_PATH,
my_strcat_no_free(path, "_base.png")), view->window);
    button->hover = create_image(my_strcat_no_free(BUTTON_PATH,
my_strcat_no_free(path, "_hover.png")), view->window);
    button->click = create_image(my_strcat_no_free(BUTTON_PATH,
my_strcat_no_free(path, "_click.png")), view->window);
    button->scene = (int) pos.z;
    button->display = button->base;
    button->trigger = trigger;
    button->hover_sound = create_sound("assets/sounds/hover.wav");
    button->click_sound = create_sound("assets/sounds/click.wav");
    button->mouse_hover = 0;
    button->mouse_click = 0;
    button->pos = V2F(pos.x, pos.y);
    button->display_pos.x = global_to_view(V2F(pos.x, pos.y), view).x;
    button->display_pos.x = global_to_view(V2F(pos.x, pos.y), view).y;
    return (button);
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
