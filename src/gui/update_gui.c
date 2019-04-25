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

static void manage_button(button_t *button, game_t *game)
{
    button->display_pos.x = global_to_view(button->pos, VIEW).x;
    button->display_pos.y = global_to_view(button->pos, VIEW).y;
    if (point_intersect(button->display,
        CURSOR->pos.x + 16, CURSOR->pos.y + 16))
        button->mouse_hover = 1;
    else
        button->mouse_hover = 0;
    if (sfMouse_isButtonPressed(sfMouseLeft) && button->mouse_hover)
        button->mouse_click = 1;
    if (!sfMouse_isButtonPressed(sfMouseLeft) && button->mouse_hover &&
button->mouse_click) {
        button->trigger(game);
        button->mouse_click = 0;
    }
    manage_button2(button);
}

static void manage_cursor(game_t *game, sfVector2i pos)
{
    CURSOR->pos.x = global_to_view_mouse(V2F(pos.x, pos.y), VIEW).x - 16;
    CURSOR->pos.y = global_to_view_mouse(V2F(pos.x, pos.y), VIEW).y - 16;
    update_anim(CURSOR->idle);
    update_anim(CURSOR->build);
    update_anim(CURSOR->inspect);
    sfSprite_setPosition(CURSOR->base->sheet->sprite, CURSOR->pos);
    if (CURSOR->mode == 0)
        CURSOR->display = CURSOR->base;
    if (CURSOR->mode == 1)
        CURSOR->display = CURSOR->idle;
    if (CURSOR->mode == 2)
        CURSOR->display = CURSOR->inspect;
    if (CURSOR->mode == 3)
        CURSOR->display = CURSOR->build;
    display_anim(CURSOR->display, CURSOR->pos);
}

void update_gui(game_t *game, sfVector2i pos)
{
    GUI->pos.x = pos.x;
    GUI->pos.y = pos.y;
    for (int i = 0; i < BUTTON_AMOUNT; i++) {
        if (GUI->button[i]->scene == game->scene)
            manage_button(GUI->button[i], game);
    }
    manage_cursor(game, GUI->pos);
}
