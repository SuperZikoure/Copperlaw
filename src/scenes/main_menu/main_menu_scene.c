/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** main_menu_scene
*/

#include "my_rpg.h"

static int analyse_main_menu_events(game_t *game, input_t *input)
{
    if (KEY_PRESSED(ESCAPE_KEY))
        return swap_main_menu_to_game(game);
    return 0;
}

int main_menu_scene(game_t *game)
{
    if (analyse_main_menu_events(game, game->input))
        return 1;
    show_scene_buttons(game);
    display_cursor(game);
    return 0;
}
