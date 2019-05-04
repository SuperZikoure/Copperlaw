/*
** EPITECH PROJECT, 2018
** graph lib
** File description:
** shapes2.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <math.h>
#include "my_rpg.h"
#include "particle.h"

void line_1(fb_t *fb, sfVector2i pa, sfVector2i pb, sfColor color)
{
    int min_x = pa.x;
    int min_y = pa.y;
    int max_x = pb.x;
    int max_y = pb.y;
    int py;
    int a;
    int b;
    int tmp;

    for (int y = min_y; y <= max_y; y++) {
        for (int x = min_x; x <= max_x; x++) {
            tmp = pa.y - pb.y;
            a = (pa.x - pb.x != 0) ? tmp / (pa.x - pb.x) : tmp;
            b = pa.y - a * pa.x;
            py = a * x + b;
            my_put_pixel(fb, x, py, color);
        }
    }
}

void line_2(fb_t *fb, sfVector2i pa, sfVector2i pb, sfColor color)
{
    int min_x = pa.x;
    int min_y = pa.y;
    int max_x = pb.x;
    int max_y = pb.y;
    int px;
    int a;
    int b;
    int tmp;

    for (int y = min_y; y <= max_y; y++) {
        for (int x = min_x; x <= max_x; x++) {
            tmp = pa.y - pb.y;
            a = (pa.x - pb.x != 0) ? tmp / (pa.x - pb.x) : tmp;
            b = pa.y - a * pa.x;
            px = (a != 0) ? ((y - b) / a) : (y - b);
            my_put_pixel(fb, px, y, color);
        }
    }
}

void line_1f(fb_t *fb, sfVector2f pa, sfVector2f pb, sfColor color)
{
    float min_x = pa.x;
    float min_y = pa.y;
    float max_x = pb.x;
    float max_y = pb.y;
    float py;
    float a;
    float b;
    float tmp;

    for (float y = min_y; y <= max_y; y++) {
        for (float x = min_x; x <= max_x; x++) {
            tmp = pa.y - pb.y;
            a = (pa.x - pb.x != 0) ? tmp / (pa.x - pb.x) : tmp;
            b = pa.y - a * pa.x;
            py = a * x + b;
            my_put_pixel(fb, x, py, color);
        }
    }
}

void line_2f(fb_t *fb, sfVector2f pa, sfVector2f pb, sfColor color)
{
    float min_x = pa.x;
    float min_y = pa.y;
    float max_x = pb.x;
    float max_y = pb.y;
    float px;
    float a;
    float b;
    float tmp;

    for (float y = min_y; y <= max_y; y++) {
        for (float x = min_x; x <= max_x; x++) {
            tmp = pa.y - pb.y;
            a = (pa.x - pb.x != 0) ? tmp / (pa.x - pb.x) : tmp;
            b = pa.y - a * pa.x;
            px = (a != 0) ? ((y - b) / a) : (y - b);
            my_put_pixel(fb, px, y, color);
        }
    }
}

void my_draw_line(fb_t *fb, sfVector2i pa, sfVector2i pb, sfColor clr)
{
    int min_x = pa.x;
    int min_y = pa.y;
    int max_x = pb.x;
    int max_y = pb.y;

    if (((max_y - min_y) / 2) <= (max_x - min_x))
        line_1(fb, pa, pb, clr);
    else
        line_2(fb, pa, pb, clr);
}
