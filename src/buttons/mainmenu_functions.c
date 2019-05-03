/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** mainmenu_functions
*/

#include "my_rpg.h"

int exit_game(game_t *game, int option __attribute__((unused)))
{
    game->exit = 1;
    return 1;
}
