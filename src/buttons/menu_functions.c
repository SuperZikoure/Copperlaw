/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** menu_functions.c
*/

#include "graph.h"
#include "my_rpg.h"

int exit_game(game_t *game, int index __attribute__((unused)))
{
    game->exit = 1;
    return 1;
}

int put_fs(game_t *game, int index __attribute__((unused)))
{
    FS = FS ? false : true;
    change_window(game->window, RES, FS);
    return 1;
}

int res_plus(game_t *game, int index __attribute__((unused)))
{
    RES += (RES < RESOLUTIONS - 1) ? 1 : 0;
    change_window(game->window, RES, FS);
    return 1;
}

int res_moins(game_t *game, int index __attribute__((unused)))
{
    RES -= (RES >= 1) ? 1 : 0;
    change_window(game->window, RES, FS);
    return 1;
}
