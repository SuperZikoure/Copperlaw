/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** mainmenu_howtoplay
*/

#include "my_rpg.h"

int swap_main_menu_to_howtoplay(game_t *game __attribute__((unused)),
                        int option __attribute__((unused)))
{
    change_scene(HOW_TO_PLAY);
    return 1;
}

int swap_howtoplay_to_main_menu(game_t *game __attribute__((unused)),
                        int option __attribute__((unused)))
{
    change_scene(MAIN_MENU);
    return 1;
}
