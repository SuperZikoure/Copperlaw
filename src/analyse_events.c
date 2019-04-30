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
            return 0;
        }
        WINDOW->width = sfRenderWindow_getSize(WINDOW->window).x;
        WINDOW->height = sfRenderWindow_getSize(WINDOW->window).y;
        if (event.type == sfEvtKeyPressed || event.type == sfEvtKeyReleased)
            process_input(game->input);
    }
    return 0;
}
