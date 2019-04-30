/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** pause_loop
*/

#include "my_rpg.h"

static int analyse_pause_events(input_t *input)
{
    if (KEY_PRESSED(ESCAPE_KEY)) {
        change_scene(GAME);
        input->keys[ESCAPE_KEY]->pressed = 0;
        return 1;
    }
    return 0;
}

int pause_scene(game_t *game)
{
    if (analyse_pause_events(game->input))
        return 1;
    return 0;
}
