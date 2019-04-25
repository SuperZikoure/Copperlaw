/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** create_game.c
*/

#include "graph.h"
#include "my_rpg.h"
#include "stdlib.h"

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

static my_clock_t *create_clock(game_t *game)
{
    my_clock_t *clock = malloc(sizeof(my_clock_t));

    clock->clock = sfClock_create();
    clock->frames = 0;
    clock->parent = game;
    return (clock);
}

static option_t create_option(void)
{
    option_t option;

    option.resolution = DEFAULT_SCREENSIZE;
    option.fullscreen = 0;
    option.music = 1;
    option.sound = 1;
    return (option);
}

game_t create_game(void)
{
    game_t game;

    game.window = create_window(DEFAULT_SCREENSIZE, "CopperLaw");
    game.input = create_input();
    game.clock = create_clock(&game);
    game.view = create_view((sfVector2f){0, 0}, SIZE, ZOOM, &game);
    game.gui = create_gui(game.view);
    game.option = create_option();
    game.exit = 0;
    game.frames = 0;
    game.maps[0] = create_map("src/data/maps/testmdr", game.window);
    game.current_map = 0;
    game.player = create_player(&game);
    return (game);
}
