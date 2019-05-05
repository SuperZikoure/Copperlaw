/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Desert particle
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "particle.h"

static void shift_sand(fb_t *particle)
{
    unsigned int i;

    for (i = 0; i < particle->x * particle->y; i++) {
        if (particle->pixels[i * 4 + 4] == 255 && i > 0) {
            particle->pixels[(i - 1) * 4 + 4] = 255;
            particle->pixels[i * 4 + 4] = 0;
        } else if (particle->pixels[i * 4 + 4] == 255) {
            particle->pixels[(particle->x * particle->y - 1) * 4 + 4] = 255;
            particle->pixels[i * 4 + 4] = 0;
        }
    }
}

static void create_sand(fb_t *particle)
{
    unsigned int i;

    for (i = 0; i < 50; i++)
        particle->pixels[rand() % (particle->x * particle->y) * 4] = 255;
}

static void set_color(fb_t *particle)
{
    unsigned int i;

    for (i = 0; i < particle->x * particle->y; i++) {
        particle->pixels[i * 4] = 240;
        particle->pixels[i * 4 + 1] = 181;
        particle->pixels[i * 4 + 2] = 65;
        particle->pixels[i * 4 + 3] = 0;
    }
}

fb_t *desert_particle(fb_t *particle, int type)
{
    static int bool_created = 0;

    type = type;
    if (!bool_created) {
        particle = framebuffer_create(1920, 1080);
        if (particle == NULL)
            return NULL;
        set_color(particle);
        create_sand(particle);
        bool_created = 1;
    }
    shift_sand(particle);
    return particle;
}
