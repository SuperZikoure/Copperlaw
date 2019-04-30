/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** loop_game
*/

#include <stdio.h>
#include "my_rpg.h"

void game_loop(game_t *game)
{
    change_scene(GAME);
    start_clock();
    while (sfRenderWindow_isOpen(game->window->window) && !game->exit) {
        start_new_frame();
        analyse_events(game);
        game->mouse_pos = sfMouse_getPositionRenderWindow(game->window->window);
        sfRenderWindow_clear(game->window->window, sfBlack);
        /* if ( */get_scene()(game);/*  == -1) */
            // sfRenderWindow_close(game->window->window);
        sfRenderWindow_setView(game->window->window, game->view->camera);
        sfRenderWindow_display(game->window->window);
    }
}
