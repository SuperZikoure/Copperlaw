/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** menu_scene
*/

#include "my_rpg.h"
#include "macros.h"

static int analyse_menu_events(game_t *game, input_t *input)
{
    if (KEY_PRESSED(ESCAPE_KEY))
        return swap_menu_to_game(game, 0);
    return 0;
}

static void display_stats(game_t *game, player_t *player)
{
    display_text("LVL :", GTV(340, 32), game->texts[BIG_TEXT]);
    display_text(my_itoa(STATS(LVL)), GTV(400, 32), game->texts[BIG_TEXT]);
    display_text("CLASS :", GTV(340, 64), game->texts[BIG_TEXT]);
    if (player->class == REVOLVER)
        display_text("REVOLVER", GTV(400, 64), game->texts[BIG_TEXT]);
    else
        display_text("SHOTGUN", GTV(400, 64), game->texts[BIG_TEXT]);
    display_text("ATTACK :", GTV(340, 128), game->texts[BIG_TEXT]);
    display_text(my_itoa(STATS(DAMAGE)), GTV(400, 128), game->texts[BIG_TEXT]);
    display_text("DEFENSE :", GTV(340, 160), game->texts[BIG_TEXT]);
    display_text(my_itoa(STATS(DEFENSE)), GTV(400, 160), game->texts[BIG_TEXT]);
    display_text("XP :", GTV(340, 192), game->texts[BIG_TEXT]);
    display_text(DISP_STATS(CURRENT_XP, MAX_XP), GTV(400, 192),
    game->texts[BIG_TEXT]);
    display_text("MP :", GTV(340, 256), game->texts[BIG_TEXT]);
    display_text(DISP_STATS(CURRENT_MP, MAX_MP), GTV(400, 256),
    game->texts[BIG_TEXT]);
    display_text("SP :", GTV(340, 288), game->texts[BIG_TEXT]);
    display_text(DISP_STATS(CURRENT_SP, MAX_SP), GTV(400, 288),
    game->texts[BIG_TEXT]);
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
    if (PLAYER->class)
        display_stats(game, PLAYER);
    show_scene_buttons(game);
    display_cursor(game);
    return 0;
}
