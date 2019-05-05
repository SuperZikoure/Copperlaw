/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Dust and bullet particles
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "particle.h"

static void clear_circle(fb_t *particle)
{
    unsigned int i;

    for (i = 0; i < particle->x * particle->y; i++) {
        if (particle->pixels[i * 4 + 3] == 255)
            particle->pixels[i * 4 + 3] = 125;
        else
            particle->pixels[i * 4 + 3] = 0;
    }
}

static void draw_dust(fb_t *particle)
{
    unsigned int max = (particle->x - 1) * (particle->y - 1);
    sfVector2i pos;
    int i;

    for (i = 0; i < 5; i++) {
        pos.x = (rand() % (max - particle->x + 5)) + particle->x + 5;
        pos.y = (rand() % (max - particle->x + 5)) + particle->x + 5;
        my_draw_fcircle(particle, pos, 3);
    }
}

static void draw_bullet_trail(fb_t *particle)
{
    unsigned int max = (particle->x - 1) * (particle->y - 1);
    sfVector2i pos;
    int i;

    for (i = 0; i < 3; i++) {
        pos.x = (rand() % (max - particle->x + 5)) + particle->x + 5;
        pos.y = (rand() % (max - particle->x + 5)) + particle->x + 5;
        my_draw_fcircle(particle, pos, 5);
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

fb_t *trail_particle(fb_t *particle, int type)
{
    static int bool_created = 0;

    if (!bool_created) {
        particle = framebuffer_create(16, 16);
        bool_created = 1;
        set_color(particle);
    }
    clear_circle(particle);
    if (type == DUST_P)
        draw_dust(particle);
    else
        draw_bullet_trail(particle);
    return particle;
}
