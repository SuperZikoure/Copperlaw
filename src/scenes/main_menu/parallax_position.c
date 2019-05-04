/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** parallax_position
*/

#include "my_rpg.h"

static float fetch_parallax_pos(float value, int option)
{
    static float pos = 0;

    if (option != -1) {
        pos = value;
        return 0;
    }
    return pos;
}

float get_parallax_pos(void)
{
    return fetch_parallax_pos(0, -1);
}

void set_parallax_pos(float value)
{
    fetch_parallax_pos(value, 0);
}
