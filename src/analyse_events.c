/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** analyse_events
*/

#include "my_rpg.h"

static void reset_keys(keypress_t **keys)
{
    for (int i = 0; i < KEY_NB; i++)
        keys[i]->pressed = 0;
}

int analyse_events(game_t *game)
{
    sfEvent event;

    reset_keys(game->input->keys);
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
