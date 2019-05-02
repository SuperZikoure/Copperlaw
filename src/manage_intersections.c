/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** manage_intersections.c
*/

#include "graph.h"
#include "my_rpg.h"
#include "stdlib.h"
#include "macros.h"

int text_intersect(sfText *text, image_t *image) {
    sfFloatRect rect1 = sfText_getGlobalBounds(text);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(image->sprite);

    if (sfFloatRect_intersects(&rect1, &rect2, NULL))
        return (1);
    return (0);
}

int point_intersect(image_t *img, float x, float y)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(img->sprite);

    if (sfFloatRect_contains(&rect, x, y))
        return (1);
    return (0);
}

int image_intersect(image_t *img1, image_t *img2)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(img1->sprite);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(img2->sprite);

    if (sfFloatRect_intersects(&rect1, &rect2, NULL))
        return (1);
    return (0);
}
