/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** scene_system
*/

#include "my_rpg.h"

int (* const scenes[SCENE_NB])(game_t *) = {
    NULL,
    NULL,
    game_scene,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

static int (*fetch_scene(int flag))(game_t *)
{
    static int id = 0;

    if (flag != -1) {
        id = flag;
        return NULL;
    }
    return scenes[id];
}

int (*get_scene(void))(game_t *)
{
    return fetch_scene(-1);
}

void change_scene(enum enum_scene_e id)
{
    fetch_scene(id);
}
