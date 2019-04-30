/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** window.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"
#include "my_rpg.h"

static int fill_window(window_t *win, int size, bool fullscreen)
{
    sfUint32 style = fullscreen ? sfClose | sfFullscreen : sfClose;

    win->width = window_size[size].width;
    win->height = window_size[size].height;
    win->mode.width = window_size[size].width;
    win->mode.height = window_size[size].height;
    win->mode.bitsPerPixel = 32;
    win->window = sfRenderWindow_create(win->mode, win->title, style, NULL);
    if (!win->window)
        return -1;
    sfRenderWindow_setFramerateLimit(win->window, 60);
    sfRenderWindow_setVerticalSyncEnabled(win->window, sfTrue);
    sfRenderWindow_setMouseCursorVisible(win->window, sfFalse);
    return 0;
}

window_t *create_window(int size, char *str)
{
    window_t *window = malloc(sizeof(window_t));

    if (!window)
        return NULL;
    window->title = str;
    if (fill_window(window, size, false) == -1)
        return NULL;
    return window;
}

int change_window(window_t *window, int size, bool fullscreen)
{
    sfRenderWindow_destroy(window->window);
    if (fill_window(window, size, fullscreen) == -1)
        return -1;
    return 0;
}

void destroy_window(window_t *window)
{
    sfRenderWindow_destroy(window->window);
    free(window);
}
