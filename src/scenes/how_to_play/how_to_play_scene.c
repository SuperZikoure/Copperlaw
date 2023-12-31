/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** main_menu_how_to_play
*/

#include "my_rpg.h"
#include "macros.h"

const char *howtoplay_txt = "[Z] to move up\n\n[S] to move down\n\n[Q] to move \
left\n\n[D] to move right\n\n[Space] to dash\n\n[Right click] to use special \
ability\n\n[Left click] to use shot \n\n[F11] to take a screenshot";

static int analyse_main_menu_events(game_t *game, input_t *input)
{
    if (KEY_PRESSED(ESCAPE_KEY))
        return swap_howtoplay_to_main_menu(game, 0);
    return 0;
}

int how_to_play_scene(game_t *game)
{
    if (analyse_main_menu_events(game, game->input))
        return 1;
    display_parallax(game);
    display_image(get_image(HOWTOPLAY_IMG), GTV(0, 0));
    display_text(howtoplay_txt, V2F(-200, -150),
game->texts[BIG_TEXT]);
    show_scene_buttons(game);
    display_cursor(game);
    return 0;
}
