/*
** EPITECH PROJECT, 2018
** gramh lib
** File description:
** shapes3.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <math.h>
#include "my_rpg.h"
#include "particle.h"

void my_draw_line_f(fb_t *fb, sfVector2f pa, sfVector2f pb, sfColor cr)
{
    float min_x = pa.x;
    float min_y = pa.y;
    float max_x = pb.x;
    float max_y = pb.y;

    if (((max_y - min_y) / 2) <= (max_x - min_x))
        line_1f(fb, pa, pb, cr);
    else
        line_2f(fb, pa, pb, cr);
}
