/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** loop_game
*/

#include "my_rpg.h"

void game_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window->window) && game->exit == 0) {
        process_input(game->window, game->input);
        sfRenderWindow_clear(game->window->window, sfBlack);
        game->mouse_pos = sfMouse_getPositionRenderWindow(game->window->window);
        //scene_manager(game, game->scene);
        if (game->scene == GAME)
            manage_game(game);
        update_gui(game, game->mouse_pos);
        sfRenderWindow_setView(game->window->window, game->view->camera);
        sfRenderWindow_display(game->window->window);
    }
}
