/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Skill and damage particules functions
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "particle.h"

static void set_color_damage(fb_t *particle, int const type)
{
    unsigned int i;

    for (i = 0; i < particle->x * particle->y; i++) {
        particle->pixels[i * 4] = 230;
        particle->pixels[i * 4 + 1] = 69;
        particle->pixels[i * 4 + 2] = 57;
        particle->pixels[i * 4 + 3] = 0;
    }
}

static void set_color_skills(fb_t *particle, int const type)
{
    unsigned int i;

    for (i = 0; i < particle->x * particle->y && type == SKILL_1_P; i++) {
        particle->pixels[i * 4] = 255;
        particle->pixels[i * 4 + 1] = 255;
        particle->pixels[i * 4 + 2] = 255;
        particle->pixels[i * 4 + 3] = 0;
    }
    for (i = 0; i < particle->x * particle->y && type == SKILL_2_P; i++) {
        particle->pixels[i * 4] = 99;
        particle->pixels[i * 4 + 1] = 171;
        particle->pixels[i * 4 + 2] = 63;
        particle->pixels[i * 4 + 3] = 0;
    }
    for (i = 0; i < particle->x * particle->y && type == SKILL_3_P; i++) {
        particle->pixels[i * 4] = 255;
        particle->pixels[i * 4 + 1] = 238;
        particle->pixels[i * 4 + 2] = 131;
        particle->pixels[i * 4 + 3] = 0;
    }
}

fb_t *skill_particle(fb_t *particle, int type)
{
    static int bool_created = 0;

    type = type;
    if (!bool_created) {
        particle = framebuffer_create(16, 16);
        bool_created = 1;
        if (type == DAMAGE_P)
            set_color_damage(particle, type);
        else
            set_color_skills(particle, type)
    }
    return particle;
}
