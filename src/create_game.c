/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** create_game.c
*/

#include "my_rpg.h"
#include "macros.h"

extern char *map_paths[MAP_AMOUNT]; 
extern char *music_paths[];
void init_npcs(game_t *game);
npc_t *create_npc(int i, window_t *window);
option_t create_option(void);
void fill_game(game_t *game);

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

static void create_maps(game_t *game)
{
    for (int i = 0; i < MAP_AMOUNT; i++) {
        game->maps[i] = create_map(map_paths[i], game->window);
        if (!game->maps[i]) {
            game->exit = -1;
            return;
        }
    }
}

static void create_texts(game_t *game)
{
    for (int i = 0; i < TEXT_AMOUNT; i++) {
        game->texts[i] = create_text(12, font_path[i], game->window);
        if (!game->texts[i]) {
            game->exit = -1;
            return;
        }
    }
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
    game.music = create_music(music_paths[0]);
    game.player = create_player(&game);
    game.inventory = create_inventory();
    init_npcs(&game);
    return (game);
}
