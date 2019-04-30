/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** mainmenu_game
*/

#include "my_rpg.h"

int swap_main_menu_to_game(game_t *game)
{
    change_scene(GAME);
    game->input->keys[ESCAPE_KEY]->pressed = 0;
    CURSOR->mode = CURSOR_IDLE;
    return 1;
}
