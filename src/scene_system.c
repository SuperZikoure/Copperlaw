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
    pause_scene,
    NULL,
    NULL,
    NULL,
    NULL
};

static int fetch_scene_id(int flag)
{
    static int id = 0;

    if (flag != -1) {
        id = flag;
        return 0;
    }
    return id;
}

int (*get_scene(void))(game_t *)
{
    return scenes[fetch_scene_id(-1)];
}

int get_scene_id(void)
{
    return fetch_scene_id(-1);
}

void change_scene(enum enum_scene_e id)
{
    fetch_scene_id(id);
}
