/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** use_items2
*/

#include "my_rpg.h"

void use_fieldratio(game_t *game)
{
    PLAYER->stats[CURRENT_SP] = PLAYER->stats[MAX_SP];
}

void use_cactusjuice(game_t *game)
{
    PLAYER->stats[CURRENT_MP] = PLAYER->stats[MAX_MP];
}

void use_tequila(game_t *game)
{
    PLAYER->stats[CURRENT_MP] = PLAYER->stats[MAX_MP];
    PLAYER->stats[CURRENT_SP] += 1;
    if (PLAYER->stats[CURRENT_SP] > PLAYER->stats[MAX_SP])
        PLAYER->stats[CURRENT_SP] = PLAYER->stats[MAX_SP];
}

void use_ethanol(game_t *game)
{
    PLAYER->stats[CURRENT_MP] = PLAYER->stats[MAX_MP];
    PLAYER->stats[CURRENT_SP] = PLAYER->stats[MAX_SP];
    PLAYER->stats[CURRENT_HP] -= 2;
}
