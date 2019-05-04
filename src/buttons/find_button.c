/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** find_button
*/

#include "my_rpg.h"
#include "macros.h"

button_t *find_button(game_t *game, char *name, enum enum_scene_e scene)
{
    button_t **buttons = GUI->button;

    for (int i = 0; i < BUTTON_AMOUNT; i++) {
        if (buttons[i]->scene == scene && STR_EQ(name, buttons[i]->name))
            return buttons[i];
    }
    return NULL;
}
