/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** fetch_image.c
*/

#include <stdlib.h>
#include <math.h>
#include "graph.h"
#include "my_rpg.h"

static image_t **fetch_image(int flag, window_t *window)
{
    static image_t **images = NULL;

    if (flag != 0)
        return images;
    images = malloc(sizeof(image_t *) * IMAGE_AMOUNT);
    if (!images)
        return NULL;
    for (int i = 0; i < IMAGE_AMOUNT; i++) {
        images[i] = create_image(image_path[i], window);
        if (!images[i])
            return NULL;
    }
    return images;
}

int fill_image(window_t *window)
{
    if (!fetch_image(0, window))
        return -1;
    return 0;
}

image_t *get_image(int index)
{
    return (fetch_image(-1, NULL)[index]);
}
