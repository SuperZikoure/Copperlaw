/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** manage_button.c
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "graph.h"
#include "my_rpg.h"
#include "my_string.h"


button_t *create_button(char *path, sfVector3f pos, view_t *view,
void (*trigger)(game_t*))
{
    button_t *button = malloc(sizeof(button_t));
    window_t *window = view->window;

    button->base = create_image(my_strcat_no_free(BUTTON_PATH,
    my_strcat_no_free(path, "_base.png")), window);
    button->hover = create_image(my_strcat_no_free(BUTTON_PATH,
    my_strcat_no_free(path, "_hover.png")), window);
    button->click = create_image(my_strcat_no_free(BUTTON_PATH,
    my_strcat_no_free(path, "_click.png")), window);
    button->scene = (int)(pos.z);
    button->display = button->base;
    button->trigger = trigger;
    button->hover_sound = create_sound("assets/sounds/hover.wav");
    button->click_sound = create_sound("assets/sounds/click.wav");
    button->mouse_hover = 0;
    button->mouse_click = 0;
    button->pos = (sfVector2f){pos.x, pos.y};
    button->display_pos.x = global_to_view((sfVector2f){pos.x, pos.y}, view).x;
    button->display_pos.x = global_to_view((sfVector2f){pos.x, pos.y}, view).y;
    return (button);
}

void manage_button2(button_t *button, game_t *game)
{
    if (!sfMouse_isButtonPressed(sfMouseLeft))
        button->mouse_click = 0;
    if (button->mouse_hover)
        button->display = button->hover;
    else
        button->display = button->base;
    if (button->mouse_click)
        button->display = button->click;
    display_image(button->display, button->display_pos);
}

void manage_button(button_t *button, game_t *game)
{
    view_t *view = game->view;
    window_t *window = game->window;
    cursor_t *cursor = game->gui->cursor;

    button->display_pos.x = global_to_view(button->pos,
    view).x;
    button->display_pos.y = global_to_view(button->pos,
    view).y;
    if (point_intersect(button->display,
        cursor->pos.x + 16, cursor->pos.y + 16))
        button->mouse_hover = 1;
    else
        button->mouse_hover = 0;
    if (sfMouse_isButtonPressed(sfMouseLeft) && button->mouse_hover)
        button->mouse_click = 1;
    if (!sfMouse_isButtonPressed(sfMouseLeft) && button->mouse_hover
    && button->mouse_click) {
        button->trigger(game);
        button->mouse_click = 0;
    }
    manage_button2(button, game);
}

void update_gui(game_t *game, sfVector2i pos)
{
    gui_t *gui = game->gui;
    view_t *view = game->view;
    window_t *window = game->window;

    gui->pos.x = pos.x;
    gui->pos.y = pos.y;
    for (int i = 0; i < BUTTON_AMOUNT; i++) {
        if (gui->button[i]->scene == game->scene)
            manage_button(gui->button[i], game);
    }
    manage_cursor(game, gui->pos);
}