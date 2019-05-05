/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** Particle system header
*/

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "my_rpg.h"

typedef struct {
    unsigned int x;
    unsigned int y;
    sfUint8 *pixels;
} fb_t;

enum particle_type_e {
    DESERT_P,
    FIRE_P,
    DASH_P,
    DUST_P,
    BULLET_P,
    DAMAGE_P,
    SKILL_1_P,
    SKILL_2_P,
    SKILL_3_P,
    MAX_PARTICLE
};

//lib/particle/framebuffer.c
fb_t *framebuffer_create(int width, int height);
void framebuffer_destroy(fb_t *framebuffer);
//void fb_clear(fb_t *fb);
void fb_empty(fb_t *fb);
//void fb_filter(fb_t *fb2, fb_t *fb, int filter);

//lib/particle/shapes1.c
void my_put_pixel_f(fb_t *framebuffer, int x, int y, sfColor color);
void my_put_pixel(fb_t *framebuffer, int x, int y, sfColor color);
void my_draw_square(fb_t *fb, sfVector2u pos, int size);
void my_draw_fcircle(fb_t *fb, sfVector2i center, int r);
void check_neg(int *x, int *y);

//lib/particle/shapes2.c
void line_1(fb_t *fb, sfVector2i pa, sfVector2i pb, sfColor color);
void line_2(fb_t *fb, sfVector2i pa, sfVector2i pb, sfColor color);
void line_1f(fb_t *fb, sfVector2f pa, sfVector2f pb, sfColor color);
void line_2f(fb_t *fb, sfVector2f pa, sfVector2f pb, sfColor color);
void my_draw_line(fb_t *fb, sfVector2i pa, sfVector2i pb, sfColor clr);

//lib/particle/shapes3.c
void my_draw_line_f(fb_t *fb, sfVector2f pa, sfVector2f pb, sfColor cr);

//particle/particles_system.c
image_t *get_particle(int type);

//particle/desert.c
fb_t *desert_particle(fb_t *particle, int type);

//particle/fire.c
fb_t *fire_particle(fb_t *particle, int type);

//particle/skill.c
fb_t *skill_particle(fb_t *particle, int type);

//particle/dash.c
fb_t *dash_particle(fb_t *particle, int type);

//particle/trail.c
fb_t *trail_particle(fb_t *particle, int type);

#endif
