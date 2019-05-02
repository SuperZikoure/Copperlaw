/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** slow_down_player
*/

#include "my_rpg.h"

void slow_down_player(player_t *player)
{
    player->dash.x += (player->dash.x > 0) ? -1 : 1;
    player->dash.y += (player->dash.y > 0) ? -1 : 1;
    if (player->dash.x <= 1.01 && player->dash.x >= -1.01)
        player->dash.x = 0;
    if (player->dash.y <= 1.01 && player->dash.y >= -1.01)
        player->dash.y = 0;
    player->speed.x += (player->speed.x > 0) ? -0.45 : 0.45;
    player->speed.y += (player->speed.y > 0) ? -0.45 : 0.45;
    if (player->speed.x <= 0.46 && player->speed.x >= -0.46)
        player->speed.x = 0;
    if (player->speed.y <= 0.46 && player->speed.y >= -0.46)
        player->speed.y = 0;
}
