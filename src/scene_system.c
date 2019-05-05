/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** scene_system
*/

#include "my_rpg.h"

const scene_swap_t scenes[SCENE_NB] = {
    main_menu_scene,
    option_scene,
    game_scene,
    inventory_scene,
    how_to_play_scene,
    NULL,
    menu_scene
};

static enum enum_scene_e fetch_scene_id(enum enum_scene_e flag)
{
    static enum enum_scene_e id = 0;

    if (flag != SCENE_NB) {
        id = flag;
        return 0;
    }
    return id;
}

int (*get_scene(void))(game_t *)
{
    return scenes[fetch_scene_id(SCENE_NB)];
}

enum enum_scene_e get_scene_id(void)
{
    return fetch_scene_id(SCENE_NB);
}

void change_scene(enum enum_scene_e id)
{
    fetch_scene_id(id);
}
