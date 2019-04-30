/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** menu_scene
*/

#include "my_rpg.h"

static int analyse_menu_events(game_t *game, input_t *input)
{
    if (KEY_PRESSED(ESCAPE_KEY))
        return swap_menu_to_game(game);
    return 0;
}

int menu_scene(game_t *game)
{
    if (analyse_menu_events(game, game->input))
        return 1;
    display_cursor(game);
    return 0;
}
