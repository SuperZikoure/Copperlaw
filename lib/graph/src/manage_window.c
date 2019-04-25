/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** window.c
*/

#include <stdlib.h>
#include "graph.h"
#include "my_rpg.h"

window_t *create_window(int size, char *str)
{
    window_t *window = malloc(sizeof(window_t) * 1);

    if (!window)
        return (NULL);
    window->width = window_size[size].width;
    window->height = window_size[size].height;
    window->mode.width = window_size[size].width;
    window->mode.height = window_size[size].height;
    window->mode.bitsPerPixel = 32;
    window->title = str;
    window->window = sfRenderWindow_create(window->mode, str,
    sfClose,
    NULL);
    if (!window->window)
        retrun (NULL);
    sfRenderWindow_setFramerateLimit(window->window, 60);
    sfRenderWindow_setVerticalSyncEnabled(window->window, sfTrue);
    sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
    return (window);
}

void change_window(window_t *window, int size, int fullscreen)
{
    if (!window)
        return (NULL);
    sfRenderWindow_destroy(window->window);
    window->width = window_size[size].width;
    window->height = window_size[size].height;
    window->mode.width = window_size[size].width;
    window->mode.height = window_size[size].height;
    window->mode.bitsPerPixel = 32;
    if (fullscreen) {
        window->window = sfRenderWindow_create(window->mode, window->title,
        sfClose | sfFullscreen, NULL);
    }
    else {
        window->window = sfRenderWindow_create(window->mode, window->title,
        sfClose, NULL);
    }
    sfRenderWindow_setFramerateLimit(window->window, 60);
    sfRenderWindow_setVerticalSyncEnabled(window->window, sfTrue);
    sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
}

void destroy_window(window_t *window)
{
    if (!window)
        return (NULL);
    sfRenderWindow_destroy(window->window);
    free(window);
}