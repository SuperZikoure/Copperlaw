/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** player_management
*/

#include "my_rpg.h"

static void teleport_player(game_t *game, sfVector3f dest, bool is_door)
{
    game->current_map = dest.z;
    PLAYER->pos.x = dest.x * C_SIZE;
    PLAYER->pos.y = dest.y * C_SIZE;
    if (is_door && SOUND)
        sfSound_play(get_door_sound()->sound);
}

static void check_teleports(game_t *game)
{
    int x = get_map_pos(PLAYER->pos.x);
    int y = get_map_pos(PLAYER->pos.y);

    for (int i = 0; i < TP_AMOUNT; i++) {
        if (game->current_map != tp_info[i].pos.z)
            continue;
        if (x == tp_info[i].pos.x && y == tp_info[i].pos.y)
            teleport_player(game, tp_info[i].dest, tp_info[i].is_door);
    }
}

void player_management(game_t *game)
{
    update_stats(PLAYER);
    check_teleports(game);
    if (game->dialogue)
        store_response(compute_dialogues_interactions(game));
    else {
        compute_game_interactions(game);
        store_response(-1);
    }
    slow_down_player(PLAYER);
    set_player_position(game);
}
