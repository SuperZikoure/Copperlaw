/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Particles system functions
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "particle.h"

fb_t *(*PARTICLE_TYPE[MAX_PARTICLE])(fb_t *, int) = {
    desert_particle
    , fire_particle
    , desert_particle/*dash_particle*/
    , desert_particle/*trail_particle*/
    , desert_particle/*trail_particle*/
    , desert_particle/*skill_particle*/
    , desert_particle/*skill_particle*/
    , desert_particle/*skill_particle*/
    , desert_particle/*skill_particle*/
};

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

image_t *get_particle(int type)
{
    static fb_t **fb_part = NULL;
    image_t *image = malloc(sizeof(image));

    if (fb_part == NULL) {
        fb_part = malloc(sizeof(fb_t *) * MAX_PARTICLE);
        if (fb_part == NULL || image == NULL)
            return NULL;
    }
    if (type != -1) {
        fb_part[type] = (*PARTICLE_TYPE[type])(fb_part[type], type);
        if (fb_part[type] == NULL)
            return NULL;
        image->texture = sfTexture_create(fb_part[type]->x, fb_part[type]->y);
        sfTexture_updateFromPixels(image->texture, fb_part[type]->pixels,
            fb_part[type]->x, fb_part[type]->y, 0, 0);
        return image;
    } else {
        free_fb(fb_part);
        free(image);
    }
    return NULL;
}
