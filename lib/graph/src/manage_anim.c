/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** anim.c
*/

#include <math.h>
#include <stdlib.h>
#include "graph.h"

anim_t *create_anim(int frames, int speed, sfVector2i size, char *sheet)
{
    anim_t *anim = malloc(sizeof(anim_t));

    anim->sheet = create_image(sheet, (sfVector2f){1, 1});
    anim->frames = frames;
    anim->speed = pow(speed, -1) * 60;
    anim->img = 0;
    anim->frame.top = 0;
    anim->frame.left = 0;
    anim->frame.width = size.x;
    anim->frame.height = size.y;
    anim->size.x = size.x;
    anim->size.y = size.y;
    anim->wait = 0;
    return (anim);
}

void update_anim(anim_t *anim)
{
    anim->wait++;
    if (anim->wait >= anim->speed) {
        anim->wait = 0;
        anim->img++;
    }
    if (anim->img >= anim->frames)
        anim->img = 0;
    anim->frame.top = anim->img * anim->size.y;
    sfSprite_setTextureRect(anim->sheet->sprite, anim->frame);
}

void display_anim(anim_t *anim, sfVector2f pos, window_t *window)
{
    display_image(anim->sheet, pos, window);
}

void destroy_anim(anim_t *anim)
{
    destroy_image(anim->sheet);
    free(anim);
}