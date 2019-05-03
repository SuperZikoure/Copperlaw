/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** menu_functions.c
*/

#include "my_rpg.h"

int change_fullscreen_mode(game_t *game, int option __attribute__((unused)))
{
    FS = FS ? false : true;
    change_window(game->window, RES, FS);
    return 1;
}

int icr_resolution(game_t *game, int option __attribute__((unused)))
{
    RES += (RES < RESOLUTIONS - 1) ? 1 : 0;
    change_window(game->window, RES, FS);
    return 1;
}

int dcr_resolution(game_t *game, int option __attribute__((unused)))
{
    RES -= (RES >= 1) ? 1 : 0;
    change_window(game->window, RES, FS);
    return 1;
}

int change_sound(game_t *game, int option __attribute__((unused)))
{
    (void) game;
    return 1;
}
