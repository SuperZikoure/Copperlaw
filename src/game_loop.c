/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** loop_game
*/

#include "my_rpg.h"

void game_loop(game_t *game)
{
    change_scene(GAME);
    start_clock();
    while (sfRenderWindow_isOpen(game->window->window) && !game->exit) {
        start_new_frame();
        process_input(game->window, game->input);
        game->mouse_pos = sfMouse_getPositionRenderWindow(game->window->window);
        sfRenderWindow_clear(game->window->window, sfBlack);
        get_scene()(game);
        sfRenderWindow_setView(game->window->window, game->view->camera);
        sfRenderWindow_display(game->window->window);
    }
}
