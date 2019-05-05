/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** menu_scene
*/

#include "my.h"
#include "my_rpg.h"
#include "macros.h"

static int analyse_menu_events(game_t *game, input_t *input)
{
    if (KEY_PRESSED(ESCAPE_KEY))
        return swap_menu_to_game(game, 0);
    return 0;
}

#include <stdio.h>

static void display_stats(game_t *game)
{
    /* do stuff here */
    printf("%s\n", my_float_to_str(game->player->stats[MAX_HP]));
}

int menu_scene(game_t *game)
{
    if (analyse_menu_events(game, game->input))
        return 1;
    display_image(get_image(PAUSE_BG), GTV(0, 0));
    display_image(get_image(BUTTON_SELECTED), GTV(0, 0));
    display_image(get_image(STATS_SELECTED), GTV(5, 11));
    display_image(get_image(BUTTON_NOT_SELECTED), GTV(0, 52));
    display_image(get_image(BUTTON_NOT_SELECTED), GTV(-64, 198));
    display_image(get_image(BUTTON_NOT_SELECTED), GTV(-64, 249));
    display_image(get_image(BUTTON_NOT_SELECTED), GTV(-64, 301));
    display_image(get_image(BUTTON_NOT_SELECTED), GTV(-64, 353));
    display_stats(game);
    show_scene_buttons(game);
    display_cursor(game);
    return 0;
}
