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

void check_click(game_t *game, npc_t *npc, sfVector2f pos, int index);

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
    display_anim(get_anim(LIFE_BAR), GTV(0, 0));
    display_anim(get_anim(MANA_BAR), GTV(0, 0));
    for (int i = 0; i < (int)PLAYER->stats[CURRENT_SP]; i++) {
        if (PLAYER->class)
            display_anim(get_anim(SP_BALL), GTV(380 + (i * 32), 15));
    }
    display_text(my_itoa(game->money), GTV(600, 36), game->texts[BIG_TEXT]);
    display_anim(get_anim(COIN), GTV(625, 30));
}

int game_scene(game_t *game)
{
    if (analyse_game_events(game, game->input))
        return 1;
    if (CURSOR->mode != CURSOR_IDLE)
        CURSOR->mode = CURSOR_IDLE;
    drop_coin(V2F(400, 400), game->coins, 0);
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
