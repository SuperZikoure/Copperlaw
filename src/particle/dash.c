/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Dash particles
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "particle.h"

static void clear_square(fb_t *particle)
{
    unsigned int i;

    for (i = 0; i < particle->x * particle->y; i++) {
        if (particle->pixels[i * 4 + 3] == 255)
            particle->pixels[i * 4 + 3] = 125;
        else
            particle->pixels[i * 4 + 3] = 0;
    }
}

static void draw_particle(fb_t *particle)
{
    sfVector2u pos;
    int i;

    for (i = 0; i < 5; i++) {
        pos.x = (rand() % ((particle->x - 5) - 5)) + particle->x - 5;
        pos.y = (rand() % ((particle->y - 5) - 5)) + particle->y + 5;
        my_draw_square(particle, pos, 3);
    }
}

static void set_color(fb_t *particle)
{
    unsigned int i;

    for (i = 0; i < particle->x * particle->y; i++) {
        particle->pixels[i * 4] = 245;
        particle->pixels[i * 4 + 1] = 255;
        particle->pixels[i * 4 + 2] = 232;
        particle->pixels[i * 4 + 3] = 0;
    }
}

fb_t *dash_particle(fb_t *particle, int type)
{
    static int bool_created = 0;

    type = type;
    if (!bool_created) {
        particle = framebuffer_create(16, 16);
        bool_created = 1;
        set_color(particle);
    }
    clear_square(particle);
    draw_particle(particle);
    return particle;
}
