/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** analyse_events
*/

#include "my_rpg.h"

int analyse_events(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(WINDOW->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(WINDOW->window);
            return 1;
        }
        if (event.type == sfEvtKeyPressed || event.type == sfEvtKeyReleased)
            process_input(game->input);
    }
    return 0;
}
