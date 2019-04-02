/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** image.c
*/

#include <stdlib.h>
#include "graph.h"

image_t *create_image(char *path, window_t *window)
{
    image_t *image = malloc(sizeof(image_t));

    image->window = window;
    image->sprite = sfSprite_create();
    image->texture = sfTexture_createFromFile(path, NULL);
    image->image = sfImage_createFromFile(path);
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    sfSprite_setPosition(image->sprite, (sfVector2f){0, 0});
    return (image);
}

void display_image(image_t *img, sfVector2f pos)
{
    sfSprite_setPosition(img->sprite, pos);
    sfRenderWindow_drawSprite(image->window->window, img->sprite, NULL);
}

void destroy_image(image_t *image)
{
    sfSprite_destroy(image->sprite);
    sfTexture_destroy(image->texture);
    sfImage_destroy(image->image);
    free(image);
}