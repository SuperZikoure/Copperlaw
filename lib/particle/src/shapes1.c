/*
** EPITECH PROJECT, 2018
** graph lib
** File description:
** shapes1.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <math.h>
#include "my_rpg.h"
#include "particle.h"

void my_put_pixel_f(fb_t *framebuffer, int x, int y, sfColor color)
{
    int pos = (x % 1 + y % 1 * framebuffer->x) * 4;

    if (x >= 1920 || y >= 1080)
        return;
    framebuffer->pixels[pos] = color.r;
    framebuffer->pixels[pos + 1] = color.g;
    framebuffer->pixels[pos + 2] = color.b;
    framebuffer->pixels[pos + 3] = color.a;
}

void my_put_pixel(fb_t *framebuffer, int x, int y, sfColor color)
{
    int pos = (x + y * framebuffer->x) * 4;

    framebuffer->pixels[pos] = color.r;
    framebuffer->pixels[pos + 1] = color.g;
    framebuffer->pixels[pos + 2] = color.b;
    framebuffer->pixels[pos + 3] = color.a;
}

void my_draw_square(fb_t *fb, sfVector2u pos, int size)
{
    for (unsigned int i = pos.y; i <= pos.y + size; i++) {
        for (unsigned int j = pos.x; j <= pos.y + size; j++) {
            fb->pixels[(i + j) * 4 + 3] = 255;
        }
    }
}

void my_draw_fcircle(fb_t *fb, sfVector2i center, int r)
{
    int height;
    int px;
    int py;

    for (int x = -r; x < r; x++) {
        height = sqrt(r * r - x * x);
        for (int y = -height; y < height; y++) {
            px = x + center.x;
            py = y + center.y;
            check_neg(&px, &py);
            fb->pixels[(px + py * fb->x) * 4] = 255;
        }
    }
}

void check_neg(int *x, int *y)
{
    if (*x < 0)
        *x = 0;
    if (*y < 0)
        *y = 0;
}
