/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** door_sound
*/

#include "my_rpg.h"

sound_t *get_door_sound(void)
{
    static sound_t *door_sound = NULL;

    if (!door_sound)
        door_sound = create_sound("assets/sounds/open_door.wav");
    return door_sound;
}

void destroy_door_sound(void)
{
    destroy_sound(get_door_sound());
}
