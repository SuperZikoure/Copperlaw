/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** sound.c
*/

#include <stdlib.h>
#include "graph.h"

sound_t *create_sound(char *path)
{
    sound_t *sound = malloc(sizeof(sound_t));

    sound->buffer = sfSoundBuffer_createFromFile(path);
    sound->sound = sfSound_create();
    sfSound_setBuffer(sound->sound, sound->buffer);
    return (sound);
}

loop_t *create_loop(char *intro_path, char *loop_path)
{
    loop_t *loop = malloc(sizeof(loop_t));

    loop->mode = 0;
    loop->intro = create_sound(intro_path);
    loop->loop = create_sound(loop_path);
    return (loop);
}

void destroy_sound(sound_t *sound)
{
    sfSound_destroy(sound->sound);
    sfSoundBuffer_destroy(sound->buffer);
    free(sound);
}

void destroy_loop(loop_t *loop)
{
    destroy_sound(loop->intro);
    destroy_sound(loop->loop);
    free(loop);
}