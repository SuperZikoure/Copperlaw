/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** manage_button.c
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "macros.h"

static void setup_view_pos(game_t *game, sfVector2f view_pos[4])
{
    float x = CAM(PLAYER->pos.x, CURSOR->pos.x, 1) + 8;

    view_pos[0] = V2F(x, CAM(PLAYER->pos.y, CURSOR->pos.y, 1) + 8);
    x = CAM(PLAYER->pos.x, CURSOR->pos.x, 0.35) + 8;
    view_pos[1] = V2F(x, CAM(PLAYER->pos.y, CURSOR->pos.y, 0.35) + 8);
    x = CAM(PLAYER->pos.x, CURSOR->pos.x, 3) + 8;
    view_pos[2] = V2F(x, CAM(PLAYER->pos.y, CURSOR->pos.y, 3) + 8);
    x = CAM(PLAYER->pos.x, CURSOR->pos.x, 4);
    view_pos[3] = V2F(x, CAM(PLAYER->pos.y, CURSOR->pos.y, 4));
}

static void edit_view(view_t *view, sfVector2f pos)
{
    sfVector2f center;

    if (pos.x < view->pos.left)
        view->pos.left = pos.x;
    if (pos.x > view->pos.left + view->pos.width)
        view->pos.left = pos.x - view->pos.width;
    if (pos.y < view->pos.top)
        view->pos.top = pos.y;
    if (pos.y > view->pos.top + view->pos.height)
        view->pos.top = pos.y - view->pos.height;
    center.x = view->pos.left + view->pos.width / 2;
    center.y = view->pos.top + view->pos.height / 2;
    sfView_setCenter(view->camera, center);
}

void update_game_gui(game_t *game)
{
    sfVector2f view_pos[4];

    CURSOR->pos.x -= 8;
    CURSOR->pos.y -= 8;
    setup_view_pos(game, view_pos);
    edit_view(game->view, view_pos[3]);
    display_cursor(game);
    display_cursor_trail(game, view_pos);
}
