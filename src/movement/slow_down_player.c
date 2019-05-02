/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** slow_down_player
*/

#include "my_rpg.h"

void slow_down_player(player_t *player)
{
    player->speed.x += (player->speed.x > 0) ? -0.45 : 0.45;
    player->speed.y += (player->speed.y > 0) ? -0.45 : 0.45;
    if (player->speed.x <= 0.46 && player->speed.x >= -0.46)
        player->speed.x = 0;
    if (player->speed.y <= 0.46 && player->speed.y >= -0.46)
        player->speed.y = 0;
}
