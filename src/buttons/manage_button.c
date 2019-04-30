/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** manage_button
*/

#include "my_rpg.h"

static void manage_button2(button_t *button)
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

static void manage_button(button_t *b, game_t *game)
{
    b->display_pos.x = global_to_view(b->pos, VIEW).x;
    b->display_pos.y = global_to_view(b->pos, VIEW).y;
    if (point_intersect(b->display, CURSOR->pos.x + 16, CURSOR->pos.y + 16))
        b->mouse_hover = 1;
    else
        b->mouse_hover = 0;
    if (sfMouse_isButtonPressed(sfMouseLeft) && b->mouse_hover)
        b->mouse_click = 1;
    if (!sfMouse_isButtonPressed(sfMouseLeft) && b->mouse_hover &&
b->mouse_click) {
        b->trigger(game);
        b->mouse_click = 0;
    }
    manage_button2(b);
}

void show_scene_buttons(game_t *game)
{
    enum enum_scene_e scene = get_scene_id();

    for (int i = 0; i < BUTTON_AMOUNT; i++) {
        if (GUI->button[i]->scene == scene)
            manage_button(GUI->button[i], game);
    }
}
