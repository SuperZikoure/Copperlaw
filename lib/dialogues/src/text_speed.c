/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** text_speed
*/

#include "dialogues.h"

static enum text_speed transfer_text_speed(int modifier)
{
    static enum text_speed speed = NORMAL;

    if (modifier != -1)
        speed = modifier;
    return speed;
}

enum text_speed get_text_speed(void)
{
    return transfer_text_speed(-1);
}

void change_text_speed(int modifier)
{
    transfer_text_speed(modifier);
}
