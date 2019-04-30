/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** pause_loop
*/

#include "my_rpg.h"

static int analyse_events(game_t *game, sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        return -1;
    if (event.)
}

static int loop_pause(game_t *game, sfRenderWindow *window)
{
    while (sfRenderWindow_isOpen(window)) {
        
    }
    return -1;
}

int start_pause(game_t *game)
{
    return loop_pause(game, WINDOW->window);
}
