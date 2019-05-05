/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** main_scene_credit
*/

#include "my_rpg.h"
#include "macros.h"

const char *credits_txt = "Credits: \n\n\nWorker 1 : Ghassane SEBAI\n\n\
Worker 2 : Nathan BELLANGER\n\nWorker 3 : Nathan LECORCHET\n\nWorker 4 : \
Briag FROUX\n\nThanks for playing";

static int analyse_main_menu_events(game_t *game, input_t *input)
{
    if (KEY_PRESSED(ESCAPE_KEY))
        return swap_credits_to_main_menu(game, 0);
    return 0;
}

int credit_scene(game_t *game)
{
    if (analyse_main_menu_events(game, game->input))
        return 1;
    display_parallax(game);
    display_image(get_image(CREDIT_IMG), GTV(0, 0));
    display_text(credits_txt, V2F(-200, -150),
game->texts[BIG_TEXT]);
    show_scene_buttons(game);
    display_cursor(game);
    return 0;
}
