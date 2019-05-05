/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** barman_shop
*/

#include "my_rpg.h"

void barman_shop(game_t *game)
{
    static int selection = 0;
    int response = get_response();
    
    if (response == -1)
        return;
    selection += response;
    if (selection >= 6) {
        selection = 0;
        return;
    } else if (response == 2)
        return;
    if (get_amount(selection, G_INVENTORY) < 99)
        add_item(selection, G_INVENTORY);
    selection = 0;
    game->dialogue = NULL;
}
