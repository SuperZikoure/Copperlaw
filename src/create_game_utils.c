/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_game_more
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "macros.h"

void fill_game(game_t *game)
{
    game->exit = 0;
    game->current_map = VILLAGE_MAP;
    game->dialogue = NULL;
    game->sound = true;
}

option_t create_option(void)
{
    option_t option;

    option.resolution = DEFAULT_SCREENSIZE;
    option.fullscreen = 0;
    option.music = 1;
    option.sound = 1;
    return (option);
}

npc_t *create_npc(int i, window_t *window)
{
    npc_t *npc = malloc(sizeof(npc_t));

    if (!npc)
        return NULL;
    npc->pos = npc_info[i].pos;
    npc->map = npc_info[i].map;
    npc->display = create_anim(npc_info[i].fps, V2I(32, 32), npc_info[i].path,
window);
    if (!npc->display)
        return NULL;
    return (npc);
}

void init_npcs(game_t *game)
{
    for (int i = 0; i < NPC_AMOUNT; i++) {
        game->npc[i] = create_npc(i, game->window);
        if (!game->npc[i]) {
            game->exit = -1;
            return;
        }
    }
}
