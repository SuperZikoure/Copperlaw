/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** main_menu_scene
*/

#include "my_rpg.h"
#include "macros.h"

static int analyse_main_menu_events(game_t *game, input_t *input)
{
    if (KEY_PRESSED(ESCAPE_KEY))
        return swap_option_to_main_menu(game, 0);
    return 0;
}

int option_scene(game_t *game)
{
    if (analyse_main_menu_events(game, game->input))
        return 1;
    display_parallax(game);
    display_image(get_image(OPTION_LOGO), GTV(0, 0));
    display_image(get_image(OPTION_RESOLUTION), GTV(85, 204));
    display_image(get_image(OPTION_OPTION), GTV(310, 115));
    show_scene_buttons(game);
    display_cursor(game);
    return 0;
}
