/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function
*/

#include "graph.h"
#include "my_rpg.h"
#include "stdlib.h"

void game_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window->window) && game->exit == 0) {
        game->clock->time = sfClock_getElapsedTime(game->clock->clock);
        if (game->clock->time.microseconds >= 1 / 60) {
            process_input(game->window, game->input);
            sfRenderWindow_clear(game->window->window, sfBlack);
            game->mouse_pos =
            sfMouse_getPositionRenderWindow(game->window->window);
            //scene_manager(game, game->scene);
            if (game->scene == GAME)
                manage_game(game);
            update_gui(game, game->mouse_pos);
            sfRenderWindow_setView(game->window->window, game->view->camera);
            sfRenderWindow_display(game->window->window);
            sfClock_restart(game->clock->clock);
        }
    }
}

int main(void)
{
    game_t game = create_game();

    game.scene = GAME;
    game_loop(&game);
    if (game.exit == -1)
        return (84);
    return (0);
}
