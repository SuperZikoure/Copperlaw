/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** view.c
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <math.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "graph.h"
#include "my.h"
#include "my_rpg.h"
#include "macros.h"

sfVector2f global_to_view(sfVector2f pos, view_t *view)
{
    sfVector2f mid = sfView_getCenter(view->camera);
    sfVector2f offset = {mid.x - VIEW_SIZE_X / 2, mid.y - VIEW_SIZE_Y / 2};

    pos.x += offset.x - view->velocity.x;
    pos.y += offset.y - view->velocity.y;
    return (pos);
}

sfVector2f global_to_view_mouse(sfVector2f pos, view_t *view)
{
    sfVector2f mid = sfView_getCenter(view->camera);
    sfVector2f new_pos = {pos.x / view->window->mode.width * VIEW_SIZE_X,
pos.y / view->window->mode.height * VIEW_SIZE_Y};
    sfVector2f offset = {mid.x - VIEW_SIZE_X / 2, mid.y - VIEW_SIZE_Y / 2};

    new_pos.x += offset.x - view->velocity.x;
    new_pos.y += offset.y - view->velocity.y;
    return (new_pos);
}

sfVector2f global_to_view_fx(sfVector2f pos, view_t *view)
{
    sfVector2f mid = sfView_getCenter(view->camera);
    sfVector2f offset = {mid.x - VIEW_SIZE_X / 2, mid.y - VIEW_SIZE_Y / 2};

    pos.x += offset.x;
    pos.y += offset.y;
    return (pos);
}

view_t *create_view(sfVector2f player_pos, int size, float zoom, game_t *game)
{
    view_t *view = malloc(sizeof(view_t));
    sfFloatRect cam = {0, 0, 480, 270};

    view->parent = game;
    view->window = game->window;
    view->velocity = V2F(0, 0);
    cam.left = player_pos.x - VIEW_SIZE_X / 2;
    cam.top = player_pos.y - VIEW_SIZE_Y / 2;
    view->camera = sfView_createFromRect(cam);
    sfView_zoom(view->camera, zoom);
    view->pos.left = player_pos.x - size * 16;
    view->pos.top = player_pos.y - size * 9;
    view->pos.width = size * 3.2 * 2;
    view->pos.height = size * 1.8 * 2;
    return (view);
}
