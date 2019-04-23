/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function
*/

#include "graph.h"
#include "my_rpg.h"
#include "stdlib.h"

scene_t init_scene(game_t game)
{
    scene_t scene;

    scene.player_pos = (sfVector2f){100, 100};
    scene.player_speed = (sfVector2f){0, 0};
    scene.dash = (sfVector2f){0, 0};
    scene.map = create_image("assets/sans titre.png", game.window);
    scene.player_image = create_image("assets/player-1.png", game.window);
    for (int i = 0; i < BALL_AMOUNT; i++) {
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
    scene.michel->hurt = create_image("assets/hurt.png", game.window);
    scene.michel->aggro = 0;
    scene.test1 = create_image("assets/test1.png", game.window);
    scene.test2 = create_image("assets/test2.png", game.window);
    return (scene);
}

my_clock_t *create_clock(game_t *game)
{
    my_clock_t *clock = malloc(sizeof(my_clock_t));

    clock->clock = sfClock_create();
    clock->frames = 0;
    clock->parent = game;
    return (clock);
}

option_t create_option(void)
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
    game.game = init_scene(game);
    return (game);
}

void game_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window->window) && game->exit == 0) {
        game->clock->time = sfClock_getElapsedTime(game->clock->clock);
        if (game->clock->time.microseconds >= 1 / 60) {
            process_input(game->window, game->input);
            sfRenderWindow_clear(game->window->window, sfBlack);
            game->mouse_pos =
            sfMouse_getPositionRenderWindow(game->window->window);
            //scene_manager(game, game->scene);
            if (game->scene == GAME)
                manage_game(game);
            update_gui(game, game->mouse_pos);
            sfRenderWindow_setView(game->window->window, game->view->camera);
            sfRenderWindow_display(game->window->window);
            sfClock_restart(game->clock->clock);
        }
    }
}

sfIntRect f_to_i_sfrect(sfFloatRect rect_f)
{
    sfIntRect rect_i = {rect_f.left, rect_f.top, rect_f.width, rect_f.height};

    return (rect_i);
}

sfVector2f i_to_f(sfVector2i vec)
{
    sfVector2f vf = {vec.x, vec.y};

    return (vf);
}

int point_intersect(image_t *img, float x, float y)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(img->sprite);

    if (sfFloatRect_contains(&rect, x, y) == 1)
        return (1);
    else
        return (0);
}

int image_intersect(image_t *img1, image_t *img2)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(img1->sprite);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(img2->sprite);
    sfFloatRect overlap;

    if (sfFloatRect_intersects(&rect1, &rect2, &overlap) == sfTrue)
        return (1);
    else
        return (0);
}

int main(int ac, char **av)
{
    game_t game = create_game();

    game.scene = GAME;
    game_loop(&game);
    if (game.exit == -1)
        return (84);
    return (0);
}