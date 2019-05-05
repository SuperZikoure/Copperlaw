/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** update_stats.c
*/

#include "my_rpg.h"

static void update_stats_shotgun(player_t *player, int level) {
    if (level == 1) {
        STATS(ATTACK_SPEED) = 4;
        STATS(ATTACK_COOLDOWN) = 60;
        STATS(ATTACK_RANGE) = 60;
        STATS(DAMAGE) = 1.5;
        return;
    }
    STATS(MAX_HP) += ((STATS(MAX_HP) + STATS(LVL)) / 2) / STATS(LVL);
    STATS(MAX_MP) += ((STATS(MAX_MP) + STATS(LVL)) / 2) / STATS(LVL);
    STATS(DEFENSE) += ((STATS(DEFENSE) + STATS(DEFENSE)) / 2) / STATS(DEFENSE);
    STATS(MOVE_SPEED) += 0.05;
    STATS(MAX_SP) += (level % 10 == 0) ? 1 : 0;
    STATS(ATTACK_SPEED) += 0.05;
    STATS(ATTACK_COOLDOWN) -= (STATS(ATTACK_COOLDOWN) >= 1) ? 1 : 0;
    STATS(ATTACK_RANGE) += 2;
    STATS(DAMAGE) += 0.1;
    player->level_up_display += 60;
}

static void update_stats_revolver(player_t *player, int level) {
    if (level == 1) {
        STATS(ATTACK_SPEED) = 4;
        STATS(ATTACK_COOLDOWN) = 30;
        STATS(ATTACK_RANGE) = 600;
        STATS(DAMAGE) = 1.5;
        return;
    }
    STATS(MAX_HP) += ((STATS(MAX_HP) + STATS(LVL)) / 2) / STATS(LVL);
    STATS(MAX_MP) += ((STATS(MAX_MP) + STATS(LVL)) / 2) / STATS(LVL);
    STATS(DEFENSE) += ((STATS(DEFENSE) + STATS(DEFENSE)) / 2) / STATS(DEFENSE);
    STATS(MOVE_SPEED) += 0.05;
    STATS(MAX_SP) += (level % 10 == 0) ? 1 : 0;
    STATS(ATTACK_SPEED) += 0.05;
    STATS(ATTACK_COOLDOWN) -= (STATS(ATTACK_COOLDOWN) >= 1) ? 1 : 0;
    STATS(ATTACK_RANGE) += 1;
    STATS(DAMAGE) += 0.05;
    player->level_up_display += 60;
}

void update_stats(player_t *player) {
    if (STATS(CURRENT_XP) >= STATS(MAX_XP)) {
        STATS(LVL) += 1;
        if (player->class == REVOLVER)
            update_stats_revolver(player, STATS(LVL));
        else if (player->class == SHOTGUN)
            update_stats_shotgun(player, STATS(LVL));
        STATS(CURRENT_XP) = (int)STATS(CURRENT_XP) % (int)STATS(MAX_XP);
        STATS(MAX_XP) += STATS(LVL);
        STATS(CURRENT_HP) = STATS(MAX_HP);
        STATS(CURRENT_MP) = STATS(MAX_MP);
        STATS(CURRENT_SP) = STATS(MAX_SP);
    }
}