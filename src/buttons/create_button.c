/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_button
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "macros.h"

static int setup_button_images(button_t *button, char *path, view_t *view)
{
    button->base = create_image(my_strcat_no_free(BUTTON_PATH,
my_strcat_no_free(path, "_base.png")), view->window);
    button->hover = create_image(my_strcat_no_free(BUTTON_PATH,
my_strcat_no_free(path, "_hover.png")), view->window);
    button->click = create_image(my_strcat_no_free(BUTTON_PATH,
my_strcat_no_free(path, "_click.png")), view->window);
    if (!button->base || !button->hover || !button->click)
        return -1;
    return 0;
}

button_t *create_button(const info_button_t *info, view_t *view)
{
    button_t *button = malloc(sizeof(button_t));

    if (!button)
        return NULL;
    if (setup_button_images(button, info->path, view) == -1)
        return NULL;
    button->scene = info->scene;
    button->display = button->base;
    button->trigger = info->trigger;
    button->hover_sound = create_sound("assets/sounds/hover.wav");
    button->click_sound = create_sound("assets/sounds/click.wav");
    if (!button->hover_sound || !button->click_sound)
        return NULL;
    button->mouse_hover = 0;
    button->mouse_click = 0;
    button->option = info->option;
    button->pos = V2F(info->pos.x, info->pos.y);
    button->display_pos = global_to_view(V2F(info->pos.x, info->pos.y), view);
    return (button);
}
