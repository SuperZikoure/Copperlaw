/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** manage_music
*/

#include <stdlib.h>
#include "graph.h"

static sfMusic *quick_music_create(char *path, float vol)
{
    sfMusic *music = sfMusic_createFromFile(path);

    if (!music)
        return NULL;
    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, vol);
    return music;
}

music_t *load_music(char *main_path, char *cover_path)
{
    music_t *music = malloc(sizeof(music_t));

    if (!music)
        return NULL;
    music->main = quick_music_create(main_path, BASE_VOLUME);
    if (!music->main)
        return NULL;
    if (cover_path) {
        music->cover = quick_music_create(cover_path, 0);
        if (!music->cover)
            return NULL;
    } else
        music->cover = NULL;
    return music;
}

void start_music(music_t *music)
{
    sfMusic_play(music->main);
    if (music->cover)
        sfMusic_play(music->cover);
}

void destroy_music(music_t *music)
{
    sfMusic_destroy(music->main);
    sfMusic_destroy(music->cover);
    free(music);
}
