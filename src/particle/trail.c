/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Dust and bullet particles
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "particle.h"

fb_t *fire_particle(fb_t *particle, int type)
{
    static int bool_created = 0;

    type = type;
    if (!bool_created) {
        particle = framebuffer_create(16, 16);
        bool_created = 1;
    }
    return particle;
}
