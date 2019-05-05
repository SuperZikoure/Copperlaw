/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** barman_shop
*/

#include "dialogues.h"

void barman_shop(game_t *game)
{
    static int sel = 1;
    int response = get_response();
    
    if (response == -1)
        return;
    sel += response;
    if (sel >= 7) {
        sel = 1;
        return;
    } else if (response == 2)
        return;
    if (get_amount(sel, G_INVENTORY) < 99 && game->money >= item_prices[sel])
        add_item(sel, G_INVENTORY);
    else {
        game->dialogue = get_dialogue(6);
        return;
    }
    game->money -= item_prices[sel];
    sel = 1;
    game->dialogue = NULL;
}

void cowboy_shop(game_t *game)
{
    int response = get_response();
    int sel = 7;
    
    if (response == -1 || response == 2)
        return;
    sel += response;
    if (get_amount(sel, G_INVENTORY) < 99 && game->money >= item_prices[sel])
        add_item(sel, G_INVENTORY);
    else {
        game->dialogue = get_dialogue(6);
        return;
    }
    game->money -= item_prices[sel];
    game->dialogue = NULL;
}

void blacksmith_shop(game_t *game)
{
    int response = get_response();
    
    if (response == -1 || response == 2)
        return;
    game->money -= 30;
    game->player->class = response == 0 ? REVOLVER : SHOTGUN;
    PLAYER->stats[CURRENT_XP] += 5;
    game->dialogue = NULL;
}
