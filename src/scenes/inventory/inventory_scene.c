/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** inventory_scene
*/

#include "my_rpg.h"
#include "macros.h"

static int analyse_inventory_events(game_t *game, input_t *input)
{
    if (KEY_PRESSED(ESCAPE_KEY))
        return swap_menu_to_game(game, 0);
    return 0;
}

static void manage_inventory(game_t *game)
{
    /* do stuff here */
    game->current_map = game->current_map;
}

int inventory_scene(game_t *game)
{
    if (analyse_inventory_events(game, game->input))
        return 1;
    display_image(get_image(PAUSE_BG), GTV(0, 0));
    display_image(get_image(BUTTON_NOT_SELECTED), GTV(0, 0));
    display_image(get_image(BUTTON_SELECTED), GTV(0, 52));
    display_image(get_image(INVENTORY_SELECTED), GTV(5, 63));
    display_image(get_image(BUTTON_NOT_SELECTED), GTV(-64, 249));
    display_image(get_image(BUTTON_NOT_SELECTED), GTV(-64, 301));
    display_image(get_image(BUTTON_NOT_SELECTED), GTV(-64, 353));
    manage_inventory(game);
    show_scene_buttons(game);
    display_cursor(game);
    return 0;
}
