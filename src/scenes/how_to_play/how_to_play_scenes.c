/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** main_menu_how_to_play
*/

#include "my_rpg.h"
#include "macros.h"

static char const *board_path = "assets/scenes/how_to_play/board.png";
static char const *msg = "[Z] to move up\n[S] to move down\n[Q] to move left\n[D] to move right[SPACE] to dash\n[F11] to make a screenshot"

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
    display_text(msg, V2F(50, 50));
    show_scene_buttons(game);
    display_cursor(game);
    return 0;
}
