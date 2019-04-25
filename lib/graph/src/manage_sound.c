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

    if (!sound)
        return (NULL);
    sound->buffer = sfSoundBuffer_createFromFile(path);
    if (!sound->buffer)
        return (NULL);
    sound->sound = sfSound_create();
    if (!sound->sound)
        return (NULL);
    sfSound_setBuffer(sound->sound, sound->buffer);
    return (sound);
}

void destroy_sound(sound_t *sound)
{
    if (!sound)
        return (NULL);
    sfSound_destroy(sound->sound);
    sfSoundBuffer_destroy(sound->buffer);
    free(sound);
}