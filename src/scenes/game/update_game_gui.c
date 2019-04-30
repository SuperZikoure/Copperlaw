/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** manage_button.c
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "graph.h"
#include "my_rpg.h"
#include "my_string.h"
#include "macros.h"

static void manage_cursor(game_t *game, sfVector2i pos)
{
    CURSOR->pos = global_to_view_mouse(V2F(pos.x, pos.y), VIEW);
    CURSOR->pos.x -= 16;
    CURSOR->pos.y -= 16;
    update_anim(CURSOR->idle);
    update_anim(CURSOR->build);
    update_anim(CURSOR->inspect);
    sfSprite_setPosition(CURSOR->base->sheet->sprite, CURSOR->pos);
    if (CURSOR->mode == 0)
        CURSOR->display = CURSOR->base;
    if (CURSOR->mode == 1)
        CURSOR->display = CURSOR->idle;
    if (CURSOR->mode == 2)
        CURSOR->display = CURSOR->inspect;
    if (CURSOR->mode == 3)
        CURSOR->display = CURSOR->build;
    display_anim(CURSOR->display, CURSOR->pos);
}

void update_game_gui(game_t *game, sfVector2i pos)
{
    GUI->pos.x = pos.x;
    GUI->pos.y = pos.y;
    manage_cursor(game, GUI->pos);
}
