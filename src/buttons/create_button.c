/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_button
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "macros.h"

button_t *create_button(char *path, sfVector3f pos, view_t *view,
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
