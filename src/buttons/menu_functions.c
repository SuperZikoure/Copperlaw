/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** menu_functions.c
*/

#include "graph.h"
#include "my_rpg.h"

void exit_game(game_t *game)
{
    game->exit = 1;
}

void put_fs(game_t *game)
{
    FS = FS ? false : true;
    change_window(game->window, RES, FS);
}

void res_plus(game_t *game)
{
    RES += (RES < RESOLUTIONS - 1) ? 1 : 0;
    change_window(game->window, RES, FS);
}

void res_moins(game_t *game)
{
    RES -= (RES >= 1) ? 1 : 0;
    change_window(game->window, RES, FS);
}
