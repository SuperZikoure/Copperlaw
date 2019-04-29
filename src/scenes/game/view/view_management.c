/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** view_management
*/

#include "my_rpg.h"
#include "macros.h"

static void setup_view_pos(game_t *game, sfVector2f view_pos[4])
{
    float x = CAM(PLAYER->pos.x, GUI->cursor->pos.x, 1) + 8;

    view_pos[0] = V2F(x, CAM(PLAYER->pos.y, GUI->cursor->pos.y, 1) + 8);
    x = CAM(PLAYER->pos.x, GUI->cursor->pos.x, 0.35) + 8;
    view_pos[1] = V2F(x, CAM(PLAYER->pos.y, GUI->cursor->pos.y, 0.35) + 8);
    x = CAM(PLAYER->pos.x, GUI->cursor->pos.x, 3) + 8;
    view_pos[2] = V2F(x, CAM(PLAYER->pos.y, GUI->cursor->pos.y, 3) + 8);
    x = CAM(PLAYER->pos.x, GUI->cursor->pos.x, 4);
    view_pos[3] = V2F(x, CAM(PLAYER->pos.y, GUI->cursor->pos.y, 4));
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

void manage_game_view(game_t *game)
{
    sfVector2f view_pos[4];

    game->gui->cursor->pos.x -= 8;
    game->gui->cursor->pos.y -= 8;
    setup_view_pos(game, view_pos);
    edit_view(game->view, view_pos[3]);
    display_cursor(game, view_pos);
}
