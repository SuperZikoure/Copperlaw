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
    ret->pixels = malloc(sizeof(sfUint8) * size);
    for (int i = 0; i < size; i++)
        ret->pixels[i] = 0;
    return (ret);
}

void framebuffer_destroy(fb_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
}

void fb_empty(fb_t *fb)
{
    int size = (fb->x * fb->y) * 4;
    for (int i = 0; i < size; i++) {
        fb->pixels[i] = 0;
    }
}
