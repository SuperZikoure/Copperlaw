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

static void display_inventory(game_t *game)
{
    for (int i = 1; i < ITEM_AMOUNT; i++) {
        display_text(AMOUNT_STR(i), GTV(325, 128 + ((i - 1) * 36)),
        game->texts[SMALL_TEXT]);
        display_text(desc_item[i], GTV(340, 123 + ((i - 1) * 36)),
        game->texts[BIG_TEXT]);
    }
}

int inventory_scene(game_t *game)
{
    if (analyse_inventory_events(game, game->input))
        return 1;
    display_image(get_image(PAUSE_BG), GTV(0, 0));
    display_image(get_image(BUTTON_NOT_SELECTED), GTV(0, 0));
    display_image(get_image(BUTTON_SELECTED), GTV(0, 52));
    display_image(get_image(INVENTORY_SELECTED), GTV(5, 63));
    display_image(get_image(BUTTON_NOT_SELECTED), GTV(-64, 198));
    display_image(get_image(BUTTON_NOT_SELECTED), GTV(-64, 249));
    display_image(get_image(BUTTON_NOT_SELECTED), GTV(-64, 301));
    display_image(get_image(BUTTON_NOT_SELECTED), GTV(-64, 353));
    display_image(get_image(ITEMS), GTV(300, 112));
    display_inventory(game);
    show_scene_buttons(game);
    display_cursor(game);
    return 0;
}
