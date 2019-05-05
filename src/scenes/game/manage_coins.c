/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** manage_coins.c
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "macros.h"

static void reset_velocity(sfVector2f *velocity, float rate)
{
    if (velocity->x != 0)
        velocity->x -= (velocity->x > 0) ? rate : -rate;
    if (velocity->y != 0)
        velocity->y -= (velocity->y > 0) ? rate : -rate;
    if (velocity->x >= rate && velocity->x <= - rate)
        velocity->x = 0;
    if (velocity->y >= rate && velocity->y <= - rate)
        velocity->y = 0;
}

static void manage_coins2(game_t *game, coin_t *coin, sfVector2f diff)
{
    if (ABS(diff.x) <= 16 && ABS(diff.y) <= 16) {
        coin->exist = 0;
        game->money++;
        coin->attract = 0;
    }
    if (coin->attract) {
        coin->vel.x += (diff.x <= 0) ? 0.6 : -0.6;
        coin->vel.y += (diff.y <= 0) ? 0.6 : -0.6;
        reset_velocity(&coin->vel, 0.25);
    }
}

void manage_coins(coin_t **coins, sfVector2f pos, game_t *game)
{
    sfVector2f diff;

    for (int i = 0; i < TOTAL_COINS_ON_MAP; i++) {
        if (!coins[i]->exist)
            continue;
        diff.x = coins[i]->pos.x - pos.x;
        diff.y = coins[i]->pos.y - pos.y;
        reset_velocity(&coins[i]->vel, 0.05);
        coins[i]->pos.x += coins[i]->vel.x;
        coins[i]->pos.y += coins[i]->vel.y;
        if (ABS(diff.x) <= 75 && ABS(diff.y) <= 75)
            coins[i]->attract = 1;
        display_anim(get_anim(COIN), coins[i]->pos);
        manage_coins2(game, coins[i], diff);
    }
}

coin_t *init_coin(void)
{
    coin_t *coin = malloc(sizeof(coin_t));

    coin->pos = (sfVector2f){0, 0};
    coin->vel = (sfVector2f){0, 0};
    coin->exist = 0;
    coin->attract = 0;
    return (coin);
}

void drop_coin(sfVector2f pos, coin_t **coins, int mode)
{
    sfVector2f vel = {(rand() % 200 + 1) / 100, (rand() % 200 + 1) / 100};

    for (int i = 0; i < TOTAL_COINS_ON_MAP; i++) {
        if (coins[i]->exist)
            continue;
        coins[i]->exist = 1;
        coins[i]->pos.x = pos.x;
        coins[i]->pos.y = pos.y;
        coins[i]->vel.x = vel.x;
        coins[i]->vel.y = vel.y;
        coins[i]->attract = mode;
        return;
    }
}