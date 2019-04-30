/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_cursor
*/

#include "my_rpg.h"
#include "macros.h"

void display_cursor(game_t *game)
{
    sfVector2f pos = {game->mouse_pos.x, game->mouse_pos.y};

    CURSOR->pos = global_to_view_mouse(pos, VIEW);
    CURSOR->pos.x -= 16;
    CURSOR->pos.y -= 16;
    sfSprite_setPosition(CURSOR->base->sheet->sprite, CURSOR->pos);
    if (CURSOR->mode == CURSOR_BASE)
        CURSOR->display = CURSOR->base;
    if (CURSOR->mode == CURSOR_IDLE)
        CURSOR->display = CURSOR->idle;
    if (CURSOR->mode == CURSOR_INSPECT)
        CURSOR->display = CURSOR->inspect;
    if (CURSOR->mode == CURSOR_BUILD)
        CURSOR->display = CURSOR->build;
    update_anim(CURSOR->display);
    display_anim(CURSOR->display, CURSOR->pos);
}
