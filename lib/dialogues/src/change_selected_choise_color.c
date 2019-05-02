/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** change_selected_choise_color
*/

#include "dialogues.h"

void change_selected_choise_color(struct selection *s, sfColor c)
{
    sfText_setColor(s->texts[s->selected], c);
}
