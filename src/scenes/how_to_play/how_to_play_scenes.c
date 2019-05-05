/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** main_menu_how_to_play
*/

#include "my_rpg.h"
#include "macros.h"

static char *board_path = "assets/scenes/how_to_play/board.png";

static int analyse_main_menu_events(game_t *game, input_t *input)
{
    if (KEY_PRESSED(ESCAPE_KEY))
        return swap_option_to_main_menu(game, 0);
    return 0;
}

int how_to_play_scene(game_t *game)
{
    if (analyse_main_menu_events(game, game->input))
        return 1;
    display_parallax(game);
    display_image(get_image(board_path), GTV(0, 0));
    display_text("c'est bon les cookies", V2F(100 , 100));
    show_scene_buttons(game);
    display_cursor(game);
    return 0;
}
