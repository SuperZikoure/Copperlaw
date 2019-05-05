/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** use_items1
*/

#include "my_rpg.h"

void use_elixir(game_t *game)
{
    PLAYER->stats[CURRENT_HP] += 2;
    if (PLAYER->stats[CURRENT_HP] > PLAYER->stats[MAX_HP])
        PLAYER->stats[CURRENT_HP] = PLAYER->stats[MAX_HP];
}

void use_beer(game_t *game)
{
    PLAYER->stats[CURRENT_HP] += 4;
    if (PLAYER->stats[CURRENT_HP] > PLAYER->stats[MAX_HP])
        PLAYER->stats[CURRENT_HP] = PLAYER->stats[MAX_HP];
}

void use_rum(game_t *game)
{
    PLAYER->stats[CURRENT_HP] = PLAYER->stats[MAX_HP];
}

void use_snakevenom(game_t *game)
{
    PLAYER->stats[CURRENT_SP] += 2;
    if (PLAYER->stats[CURRENT_SP] > PLAYER->stats[MAX_SP])
        PLAYER->stats[CURRENT_SP] = PLAYER->stats[MAX_SP];
}
