/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** mainmenu_credits
*/

#include "my_rpg.h"

int swap_main_menu_to_credits(game_t *game __attribute__((unused)),
                        int option __attribute__((unused)))
{
    change_scene(CREDIT);
    return 1;
}

int swap_credits_to_main_menu(game_t *game __attribute__((unused)),
                        int option __attribute__((unused)))
{
    change_scene(MAIN_MENU);
    return 1;
}
