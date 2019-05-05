/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** main_scene_credit
*/

#include "my_rpg.h"
#include "macros.h"

static char const *msg = "Credits\nWorker n°1 : Ghassane SEBAI\nWorker n°2 : Nathan BELLANGER\nWorker n°3 : Nathan LECORCHET\nWorker n°4 : Briag FROUX\nThanks for playing";

static int analyse_main_menu_events(game_t *game, input_t *input)
{
    if (KEY_PRESSED(ESCAPE_KEY))
        return swap_howtoplay_to_main_menu(game, 0);
    return 0;
}

int credit_scene(game_t *game)
{
    if (analyse_main_menu_events(game, game->input))
        return 1;
    display_parallax(game);
    display_image(get_image(CREDIT_IMG), GTV(0, 0));
    display_text(msg, V2F(-200, -150),
game->texts[BIG_TEXT]);
    show_scene_buttons(game);
    display_cursor(game);
    return 0;
}
