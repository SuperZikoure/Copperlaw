/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** create_game.c
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "macros.h"

/*static scene_t init_scene(game_t game)
{
    scene_t scene;

    scene.player_pos = (sfVector2f){100, 100};
    scene.player_speed = (sfVector2f){0, 0};
    scene.dash = (sfVector2f){0, 0};
    scene.map = create_image("assets/sans titre.png", game.window);
    scene.player_image = create_image("assets/player-1.png", game.window);
    for (int i = 0; i < PLAYER_BALLS; i++) {
        scene.balls[i] = malloc(sizeof(ball_t));
        scene.balls[i]->ball = create_image("assets/ball.png", game.window);
        scene.balls[i]->pos = (sfVector2f){0, 0};
        scene.balls[i]->speed = (sfVector2f){0, 0};
        scene.balls[i]->exist = 0;
    }
    scene.michel = malloc(sizeof(monster_t));
    scene.michel->pos = (sfVector2f){350, 350};
    scene.michel->speed = (sfVector2f){0, 0};
    scene.michel->normal = create_image("assets/normal.png", game.window);
    scene.michel->hit = create_image("assets/hurt.png", game.window);
    scene.michel->aggro = 0;
    scene.test1 = create_image("assets/test1.png", game.window);
    scene.test2 = create_image("assets/test2.png", game.window);
    return (scene);
}*/

static option_t create_option(void)
{
    option_t option;

    option.resolution = DEFAULT_SCREENSIZE;
    option.fullscreen = 0;
    option.music = 1;
    option.sound = 1;
    return (option);
}

static npc_t *create_npc(int i, window_t *window)
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

static void init_npcs(game_t *game)
{
    for (int i = 0; i < NPC_AMOUNT; i++) {
        game->npc[i] = create_npc(i, game->window);
        if (!game->npc[i]) {
            game->exit = -1;
            return;
        }
    }
}

static void fill_game(game_t *game)
{
    game->exit = 0;
    game->current_map = 0;
    game->dialogue = NULL;
    game->sound = true;
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
    game.maps[0] = create_map("src/data/maps/village", game.window);
    if (!game.maps[0])
        return game;
    game.player = create_player(&game);
    init_npcs(&game);
    return (game);
}
