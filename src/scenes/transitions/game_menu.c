/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** game_to_menu
*/

#include "my_rpg.h"

int swap_game_to_menu(game_t *game, int option __attribute__((unused)))
{
    change_scene(MENU);
    CURSOR->mode = CURSOR_BASE;
    return 1;
}

int swap_menu_to_game(game_t *game, int option __attribute__((unused)))
{
    change_scene(GAME);
    CURSOR->mode = CURSOR_IDLE;
    return 1;
}
