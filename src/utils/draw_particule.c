/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** draw_particule
*/

#include "my_rpg.h"

void draw_particule(image_t *image, sfVector2f pos)
{
    display_image(image, pos);
    destroy_image(image);
}
