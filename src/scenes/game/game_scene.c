/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** game_scene.c
*/

#include <stdlib.h>
#include <math.h>
#include "dialogues.h"
#include "macros.h"
#include <stdio.h>

void check_click(game_t *game, npc_t *npc, sfVector2f pos, int index);

// void reset_velocity(sfVector2f *velocity, float rate)
// {
//     if (velocity->x != 0)
//         velocity->x -= (velocity->x > 0) ? rate : -rate;
//     if (velocity->y != 0)
//         velocity->y -= (velocity->y > 0) ? rate : -rate;
//     if (velocity->x >= rate && velocity->x <= - rate)
//         velocity->x = 0;
//     if (velocity->y >= rate && velocity->y <= - rate)
//         velocity->y = 0;
// }

// void manage_michel(monster_t *michel, ball_t *balls[PLAYER_BALLS], sfVector2f pos)
// {
//         sfVector2f diff = (sfVector2f){michel->pos.x - pos.x, michel->pos.y - pos.y};

//     for (int i = 0; i < PLAYER_BALLS; i++) {
//         if (!balls[i]->exist)
//             continue;
//         if ((michel->speed.x + michel->speed.y && image_intersect(balls[i]->ball, michel->hit)) || (!(michel->speed.x + michel->speed.y) && image_intersect(balls[i]->ball, michel->normal))) {
//             michel->speed = (sfVector2f){balls[i]->speed.x / 5, balls[i]->speed.y / 5};
//             balls[i]->exist = 0;
//         }
//     }
//     if (ABS(diff.x) <= 200 && ABS(diff.y) <= 200)
//         michel->aggro = 1;
//     else
//         michel->aggro = 0;
//     if (michel->aggro) {
//         michel->speed.x += (diff.x <= 0) ? 0.6 : -0.6;
//         michel->speed.y += (diff.y <= 0) ? 0.6 : -0.6;
//     }
//     michel->pos.x += michel->speed.x;
//     michel->pos.y += michel->speed.y;
//     reset_velocity(&michel->speed, 1);
//     if (michel->speed.x <= 1.01 && michel->speed.x >= -1.01)
//         michel->speed.x = 0;
//     if (michel->speed.y <= 1.01 && michel->speed.y >= -1.01)
//         michel->speed.y = 0;
//     if (michel->speed.x + michel->speed.y)
//         display_image(michel->hit, michel->pos);
//     else
//         display_image(michel->normal, michel->pos);
// }

static void npc_management(game_t *game)
{
    for (int i = 0; i < NPC_AMOUNT; i++) {
        if (game->npc[i]->map == game->current_map) {
            update_anim(game->npc[i]->display);
            check_click(game, game->npc[i], game->gui->cursor->pos, i);
        }
    }
    if (game->current_map == VILLAGE_MAP)
        blacksmith_shop(game);
    if (game->current_map == SALOON_MAP)
        barman_shop(game);
    if (game->current_map == WILD_MAP)
        cowboy_shop(game);
}

static int analyse_game_events(game_t *game, input_t *input)
{
    if (KEY_PRESSED(ESCAPE_KEY))
        return swap_game_to_menu(game, 0);
    return 0;
}

static void display_hud(game_t *game)
{
    player_t *player = game->player;

    display_image(get_image(HUD), GTV(0, 0));
    show_scene_buttons(game);
    display_image(get_image(HUD_ITEMS), GTV(0, 0));
    for (int i = 1; i < ITEM_AMOUNT; i++) {
        display_text(AMOUNT_STR(i), GTV(690, 88 + ((i - 1) * 36)),
        game->texts[SMALL_TEXT]);
    }
    display_text(DISP_STATS(CURRENT_HP, MAX_HP), GTV(280, 6),
    game->texts[BIG_TEXT]);
    display_text(DISP_STATS(CURRENT_MP, MAX_MP), GTV(170, 55),
    game->texts[BIG_TEXT]);
}

int game_scene(game_t *game)
{
    if (analyse_game_events(game, game->input))
        return 1;
    if (CURSOR->mode != CURSOR_IDLE)
        CURSOR->mode = CURSOR_IDLE;
    display_image(game->maps[game->current_map]->bg, V2F(0, 0));
    display_mobs(game);
    player_management(game);
    npc_management(game);
    manage_coins(game->coins, PLAYER->pos, game);
    display_image(game->maps[game->current_map]->fg, V2F(0, 0));
    display_balls(PLAYER->balls);
    display_hud(game);
    update_game_gui(game);
    return 0;
}
