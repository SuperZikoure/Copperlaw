/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** slow_down_player
*/

#include "my_rpg.h"

void slow_down_player(player_t *player)
{
    long delta = get_delta();
    long d_distance = delta;
    float dash_min = d_distance + .01;

    player->speed.x += (player->speed.x > 0) ? -0.45 : 0.45;
    player->speed.y += (player->speed.y > 0) ? -0.45 : 0.45;
    if (player->speed.x <= 0.46 && player->speed.x >= -0.46)
        player->speed.x = 0;
    if (player->speed.y <= 0.46 && player->speed.y >= -0.46)
        player->speed.y = 0;
    player->dash.x += (player->dash.x > 0) ? -delta : delta;
    player->dash.y += (player->dash.y > 0) ? -delta : delta;
    if (player->dash.x <= dash_min && player->dash.x >= -dash_min)
        player->dash.x = 0;
    if (player->dash.y <= dash_min && player->dash.y >= -dash_min)
        player->dash.y = 0;
}
