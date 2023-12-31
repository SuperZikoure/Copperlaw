/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Particles system functions
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "particle.h"

const particle_types_t particle_types[MAX_PARTICLE] = {
    desert_particle,
    fire_particle,
    dash_particle,
    trail_particle,
    trail_particle,
    skill_particle,
    skill_particle,
    skill_particle,
    skill_particle
};

static image_t *load_fb_in_image(window_t *window, fb_t *particle)
{
    image_t *image = malloc(sizeof(image_t));

    if (image == NULL)
        return NULL;
    image->texture = sfTexture_create(particle->x, particle->y);
    sfTexture_updateFromPixels(image->texture, particle->pixels, particle->x,
particle->y, 0, 0);
    image->sprite = sfSprite_create();
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    image->image = NULL;
    image->window = window;
    return image;
}

static void free_fb(fb_t **fb_part)
{
    int i;

    for (i = 0; i < MAX_PARTICLE; i++) {
        if (fb_part[i] != NULL) {
            free(fb_part[i]->pixels);
            free(fb_part[i]);
        }
    }
    free(fb_part);
}

image_t *get_particle(window_t *window, int type)
{
    static fb_t **fb_part = NULL;

    if (fb_part == NULL) {
        fb_part = malloc(sizeof(fb_t *) * MAX_PARTICLE);
        if (fb_part == NULL)
            return NULL;
    }
    if (type != -1) {
        fb_part[type] = particle_types[type](fb_part[type], type);
        if (fb_part[type] == NULL)
            return NULL;
        return load_fb_in_image(window, fb_part[type]);
    } else
        free_fb(fb_part);
    return NULL;
}
