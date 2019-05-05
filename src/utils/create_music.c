/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_music
*/

#include "my_rpg.h"

sfMusic *create_music(const char *path)
{
    sfMusic *music = sfMusic_createFromFile(path);

    if (!music)
        return NULL;
    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, BASE_VOLUME);
    return music;
}
