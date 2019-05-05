/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** check_click
*/

#include "dialogues.h"
#include "macros.h"

static void check_lore(int index, int *changed)
{
    if (index == 2 && *changed == 0) {
        ++(*changed);
    } else if (index == 1 && *changed == 2) {
        ++(*changed);
    }
}

static void update_dialogues(game_t *game, int *changed)
{
    if (*changed == 1 && !game->dialogue) {
        ++(*changed);
        destroy_current_dialogue_script();
        load_dialogue_scene(WEAPON);
        for (int i = 0; i < 30; i++)
            drop_coin(npc_info[2].pos, game->coins, 1);
    } else if (*changed == 3 && !game->dialogue) {
        ++(*changed);
        destroy_current_dialogue_script();
        load_dialogue_scene(VILLAGE);
    }
}

void check_click(game_t *game, npc_t *npc, sfVector2f pos, int index)
{
    float distance = get_distance(PLAYER->pos, npc->pos);
    static int changed = 0;

    update_dialogues(game, &changed);
    if (distance > C_SIZE * 5)
        return;
    display_anim(get_anim(CAN_TALK), V2F(npc->pos.x + 16, npc->pos.y - 16));
    if (point_intersect(npc->display->sheet, pos.x + C_SIZE, pos.y + C_SIZE)) {
        CURSOR->mode = CURSOR_INSPECT;
        if (MOUSE_PRESSED(sfMouseLeft) && !game->dialogue) {
            check_lore(index, &changed);
            game->dialogue = get_dialogue(npc_info[index].dialogue);
        }
    }
}
