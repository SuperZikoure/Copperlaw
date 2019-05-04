/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Fire particle
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "particle.h"

static void create_fire(fb_t *particle)
{
    unsigned int i;

    for (i = 0; i < 50; i++) {
        if (!(rand() % 4))
        particle->pixels[rand() % (particle->x * particle->y) * 4] = 255;
    }
}

static void clear_fire(fb_t *particle)
{
    unsigned int i;

    for (i = 0; i < 50; i++)
        particle->pixels[rand() % (particle->x * particle->y) * 4] = 0;
}

static void set_color(fb_t *particle)
{
    unsigned int i;

    for (i = 0; i < particle->x * particle->y; i++) {
        if (rand() % 3) {
            particle->pixels[i * 4] = 230;
            particle->pixels[i * 4 + 1] = 69;
            particle->pixels[i * 4 + 2] = 57;
            particle->pixels[i * 4 + 3] = 0;
        } else {
            particle->pixels[i * 4] = 255;
            particle->pixels[i * 4 + 1] = 137;
            particle->pixels[i * 4 + 2] = 51;
            particle->pixels[i * 4 + 3] = 0;
        }
    }
}

fb_t *fire_particle(fb_t *particle, int type)
{
    static int bool_created = 0;

    type = type;
    if (!bool_created) {
        particle = framebuffer_create(16, 16);
        bool_created = 1;
        set_color(particle);
    }
    clear_fire(particle);
    create_fire(particle);
    return particle;
}
