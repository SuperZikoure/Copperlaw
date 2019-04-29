/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** dash
*/

#include "my_rpg.h"
#include "macros.h"

static void begin_dash(sfVector2f *dash, sfVector2f vel, sfVector2f dir)
{
    if (ABS(vel.x) + ABS(vel.y) >= .5) {
        if (ABS(vel.x) - ABS(vel.y) >= 1) {
            dash->x = vel.x * 6.5;
            dash->y = vel.y * 6.5;
        } else {
            dash->x = vel.x * 5;
            dash->y = vel.y * 5;
        }
    } else {
        if ((dir.x >= .2 && dir.x <= .8) || (dir.x <= -0.2 && dir.x >= -0.8)) {
            dash->x = dir.x * 25;
            dash->y = dir.y * 25;
        } else {
            dash->x = dir.x * 15;
            dash->y = dir.y * 15;
        }
    }
}

#include <stdio.h>

void dash(input_t *input, sfVector2f *dash, sfVector2f vel, sfVector2f dir)
{
    static int timer = 0;

    if (KEY_HELD(SPACE_KEY) && timer == 0) {
        timer = 60;
        begin_dash(dash, vel, dir);
    }
    dash->x += (dash->x > 0) ? -1 : 1;
    dash->y += (dash->y > 0) ? -1 : 1;
    if (dash->x <= 1.01 && dash->x >= -1.01)
        dash->x = 0;
    if (dash->y <= 1.01 && dash->y >= -1.01)
        dash->y = 0;
    if (timer > 0) {
        timer -= get_delta();
        if (timer < 0)
            timer = 0;
    }
}
