/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** window.c
*/

#include <stdlib.h>
#include "graph.h"

window_t *create_frame(int width, int height, char *str)
{
    window_t *window = malloc(sizeof(window_t) * 1);

    window->width = width;
    window->height = height;
    window->mode.width = width;
    window->mode.height = height;
    window->mode.bitsPerPixel = 32;
    window->window = sfRenderWindow_create(window->mode, str,
    sfResize | sfClose,
    NULL);
    sfRenderWindow_setFramerateLimit(window->window, 60);
    sfRenderWindow_setVerticalSyncEnabled(window->window, sfTrue);
    sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
    return (window);
}

void destroy_window(window_t *window)
{
    sfRenderWindow_destroy(window->window);
    free(window);
}