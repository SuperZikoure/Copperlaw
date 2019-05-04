/*
** EPITECH PROJECT, 2018
** graph lib
** File description:
** framebuffer.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <math.h>
#include "my_rpg.h"
#include "particle.h"

fb_t *framebuffer_create(int width, int height)
{
    fb_t *ret = malloc(sizeof(fb_t));
    int size = width * height * 4;

    if (ret == NULL)
        return NULL;
    ret->y = height;
    ret->x = width;
    ret->pixels = malloc(sizeof(sfUint8) * height * width * 4);
    for (int i = 0; i < size; i++) {
        ret->pixels[i] = 0;
    }
    return (ret);
}

void framebuffer_destroy(fb_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
}

/*void fb_clear(fb_t *fb)
{
    int size = (fb->x * fb->y) * 4;
    for (int i = 0; i < size; i++) {
        if (fb->pixels[i] != 0)
            fb->pixels[i] -= 5;
        if (fb->pixels[i] < 0)
            fb->pixels[i] = 0;
    }
}*/

void fb_empty(fb_t *fb)
{
    int size = (fb->x * fb->y) * 4;
    for (int i = 0; i < size; i++) {
        fb->pixels[i] = 0;
    }
}

/*void fb_filter(fb_t *fb2, fb_t *fb, int filter)
{
    int size = (fb2->x * fb2->y) * 4;
    for (int i = 0; i < size; i++) {
        if (fb->pixels[i] != 0)
            fb->pixels[i] -= 10;
        if (fb->pixels[i] < 0)
            fb->pixels[i] = 0;
        if (fb2->pixels[i] != 0)
            fb2->pixels[i] -= 10;
        if (fb2->pixels[i] < 0)
            fb2->pixels[i] = 0;
        if (i % filter == 0 && fb->pixels[i] > 0) {
            fb2->pixels[i] = fb->pixels[i];
            fb2->pixels[i - 1] = 255;
            fb2->pixels[i - 2] = 255;
            fb2->pixels[i - 3] = 255;
        }
        if (i < 0 && i % 3)
            fb2->pixels[i] = 0;
    }
}*/
