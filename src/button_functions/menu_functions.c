/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** menu_functions.c
*/

#include "graph.h"
#include "my_rpg.h"

#define RES game->option.resolution
#define FS game->option.fullscreen

void change_cursor(game_t *game)
{
    cursor_t *cursor = game->gui->cursor;
    cursor->mode++;

    if (cursor->mode > 3)
        cursor->mode = 0;
    if (cursor->mode < 0)
        cursor->mode = 3;
}

void put_game_scene(game_t *game)
{
    game->scene = GAME;
}

void exit_game(game_t *game)
{
    game->exit = 1;
}

void put_fs(game_t *game)
{
    FS = (FS == 1) ? 0 : 1;
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