/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** create_game.c
*/

#include "my_rpg.h"
#include "macros.h"
#include <stdlib.h>

extern char *map_paths[MAP_AMOUNT];
void init_npcs(game_t *game);
npc_t *create_npc(int i, window_t *window);
option_t create_option(void);
void fill_game(game_t *game);

static void create_maps(game_t *game)
{
    for (int i = 0; i < MAP_AMOUNT; i++) {
        game->maps[i] = create_map(map_paths[i], game->window);
        if (!game->maps[i]) {
            game->exit = -1;
            return;
        }
    }
    game->monsters[0] = create_monster(V2F(500, 500), game->window);
    game->monsters[1] = create_monster(V2F(600, 500), game->window);
    game->monsters[2] = create_monster(V2F(700, 500), game->window);
    game->monsters[3] = create_monster(V2F(800, 500), game->window);
    game->monsters[4] = create_monster(V2F(900, 500), game->window);
}

static void create_texts(game_t *game)
{
    for (int i = 0; i < TEXT_AMOUNT; i++) {
        game->texts[i] = create_text(font_size[i], font_path[i], game->window);
        if (!game->texts[i]) {
            game->exit = -1;
            return;
        }
    }
}

static int create_game_2(game_t *game)
{
    game->music = load_music(GET_MUSIC_PATHS(MAIN_MENU_MUSIC));
    if (!game->music)
        return -1;
    game->player = create_player(game);
    if (!game->player)
        return -1;
    game->inventory = create_inventory();
    if (!game->inventory)
        return -1;
    init_npcs(game);
    game->coins = malloc(sizeof(coin_t *) * TOTAL_COINS_ON_MAP);
    if (!game->coins)
        return -1;
    for (int i = 0; i < TOTAL_COINS_ON_MAP; i++)
        game->coins[i] = init_coin();
    return 0;
}

game_t create_game(void)
{
    game_t game;

    fill_game(&game);
    game.window = create_window(DEFAULT_SCREENSIZE, "CopperLaw");
    game.input = create_input();
    if (!game.window || !game.input)
        return game;
    game.view = create_view(V2F(0, 0), SIZE, ZOOM, &game);
    if (!game.view)
        return game;
    game.gui = create_gui(game.view);
    game.option = create_option();
    create_maps(&game);
    create_texts(&game);
    if (create_game_2(&game) == -1)
        game.exit = -1;
    return (game);
}
