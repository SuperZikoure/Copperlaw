/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** my_rpg.h
*/

#ifndef MY_RPG_H_
#define MY_RPG_H

#include <math.h>
#include "graph.h"

#define BUTTON_PATH ("assets/buttons/")

#define ZOOM 1.5
#define VIEW_SIZE_X (480 * ZOOM) //720
#define VIEW_SIZE_Y (270 * ZOOM) //405
#define SIZE 10

#define STATS_AMOUNT 21

#define PLAYER_BALLS 200
#define MONSTER_BALLS 25

#define CELL_SIZE 16

#define BUTTON_AMOUNT 4

#define KEY_AMOUNT 13

#define MAP_AMOUNT 1

#define DEFAULT_SCREENSIZE 4
#define RESOLUTIONS 6

#define IMAGE_AMOUNT 2

#define KEY_PRESSED(c) (input->keys[c]->pressed)
#define KEY_HELD(c) (input->keys[c]->held)

#define MOUSE_PRESSED(c) (mouse_pressed_once(c))
#define MOUSE_HELD(c) (fMouse_isButtonPressed(c))

#define WINDOW game->window
#define VIEW game->view
#define CURSOR game->gui->cursor
#define GUI game->gui
#define PLAYER game->player

#define RES game->option.resolution
#define FS game->option.fullscreen

typedef struct game_s game_t;
typedef struct info_button_s info_button_t;

struct info_button_s
{
    sfVector3f pos;
    char *path;
    void (*trigger)(game_t*);
};

extern const sfVideoMode window_size[RESOLUTIONS];
extern const char *image_path[IMAGE_AMOUNT];
extern const info_button_t info[BUTTON_AMOUNT];
extern const sfKeyCode input_key[KEY_AMOUNT];

enum enum_scene_e {
    MAIN_MENU,
    OPTIONS,
    GAME,
    PAUSE,
    INVENTORY,
    SKILLS,
    STATS,
    MENU
};

enum zone_ids {
    INTRO,
    VILLAGE,
    ZONE_NB
};

#define DELETE -1

enum enum_images_e {
    TRAIL_1,
    TRAIL_2
};

enum direction_e {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

enum direction_extented_e {
    NORTH,
    NORTH_EAST,
    EAST,
    SOUTH_EAST,
    SOUTH,
    SOUTH_WEST,
    WEST,
    NORTH_WEST
};

enum enum_stats_e {
    MAX_HP,
    CURRENT_HP,
    MAX_MP,
    CURRENT_MP,
    MAX_SP,
    CURRENT_SP,
    MOVE_SPEED,
    DASH_COOLDOWN,
    ATTACK_SPEED,
    ATTACK_COOLDOW,
    ATTACK_RANGE,
    DAMAGE,
    DEFENSE,
    CURRENT_XP,
    MAX_XP,
    CURRENT_LEVEL,
    MAX_LEVEL,
    SP_POINTS,
    SKILL_SET,
    SKILL_1_COOLDOWN,
    SKILL_2_COOLDOWN
};

enum enum_key_e {
    UP_KEY,
    RIGHT_KEY,
    DOWN_KEY,
    LEFT_KEY,
    ENTER_KEY,
    ESCAPE_KEY,
    SPACE_KEY,
    ACTION_KEY,
    ITEM_KEY,
    MENU_KEY,
    SKILL_1_KEY,
    SKILL_2_KEY,
    SKILL_3_KEY
};

typedef struct button_s
{
    void (*trigger)(game_t *);
    image_t *base;
    image_t *hover;
    image_t *click;
    image_t *display;
    sound_t *hover_sound;
    sound_t *click_sound;
    sfVector2f pos;
    sfVector2f display_pos;
    int scene;
    int mouse_hover;
    int mouse_click;
    void* parent;
} button_t;

typedef struct cursor_s
{
    sfVector2f pos;
    anim_t *base;
    anim_t *idle;
    anim_t *inspect;
    anim_t *build;
    anim_t *display;
    int mode;
    void *parent;
} cursor_t;

typedef struct gui_s {
    cursor_t *cursor;
    button_t *button[BUTTON_AMOUNT];
    sfVector2i pos;
    void *parent;
} gui_t;

typedef struct view_s {
    window_t *window;
    sfView *camera;
    sfFloatRect pos;
    sfVector2f size;
    sfVector2f offset;
    sfVector2f velocity;
    void *parent;
} view_t;

typedef struct my_clock_s {
    sfClock *clock;
    sfTime time;
    int frames;
    void *parent;
} my_clock_t;

typedef struct option_s {
    unsigned short int resolution;
    unsigned short int fullscreen;
    unsigned short int music;
    unsigned short int sound;
} option_t;

typedef struct map_s {
    char **map;
    sfVector2i size;
    image_t *bg;
    image_t *fg;
} map_t;

typedef struct col_s {
    float max[4];
    sfVector2f *pos;
    sfVector2f save;
    sfVector3f hitbox;
    int current_map;
    map_t *maps[MAP_AMOUNT];
} col_t;

typedef struct ball_s {
    sfVector2f pos;
    sfVector2f speed;
    sfVector2f *target;
    float distance;
    int damage;
    int exist;
    int type;
    int timer;
    image_t *ball;
    col_t col;
} ball_t;

typedef struct monster_s {
    sfVector2f pos;
    sfVector2f speed;
    sfVector2f bump;
    sfVector2f vel;
    int aggro;
    anim_t **move;
    anim_t **hurt;
    anim_t *idle;
    anim_t *display;
    image_t *normal; //FUCK
    image_t *hit; //FUCK
    float stats[STATS_AMOUNT];
    ball_t *attacks[MONSTER_BALLS];
    col_t col;
} monster_t;

typedef struct input_s {
    keypress_t *keys[KEY_AMOUNT];
} input_t;

typedef struct player_s {
    sfVector2f pos;
    sfVector2f speed;
    sfVector2f dash;
    sfVector2f bump;
    sfVector2f vel;
    int direction;
    int direction_2;
    sfVector2f dir;
    float mouse_distance;
    anim_t *move;
    anim_t *hurt[4];
    anim_t *idle;
    anim_t *display;
    float stats[STATS_AMOUNT];
    float boost[STATS_AMOUNT];
    ball_t *attacks[PLAYER_BALLS];
    col_t col;
    int moving;
} player_t;

struct game_s {
    window_t *window;
    my_clock_t *clock;
    view_t *view;
    gui_t *gui;
    input_t *input;
    option_t option;
    player_t *player;
    int current_map;
    map_t *maps[MAP_AMOUNT];
    sfVector2i mouse_pos;
    int frames;
    int exit;
    int scene;
};

/* game loop */
void game_loop(game_t *game);

/* gui/create_gui.c */

gui_t *create_gui(view_t *view);

/* gui/update_gui.c */

void update_gui(game_t *game, sfVector2i pos);

/* manage_intersections.c */

int point_intersect(image_t *img, float x, float y);
int image_intersect(image_t *img1, image_t *img2);

/* create_game.c */

game_t create_game(void);

/* scenes/game/manage_game.c */

void manage_game(game_t *game);

/* maps/create_map.c */

map_t *create_map(char *filepath, window_t *window);

/* create_player.c */

player_t *create_player(game_t *game);

/* movement/move_player.c */

void move_player(player_t *player, int dir);

/* manage_collisions.c */

// void compute_col(col_t *col, int current_map);

/* fetch_image.c */

int fill_image(window_t *window);
image_t *get_image(int index);

/* BUTTON FUNCTIONS */

void change_cursor(game_t *game);
void put_game_scene(game_t *game);
void exit_game(game_t *game);
void res_moins(game_t *game);
void res_plus(game_t *game);
void put_fs(game_t *game);

////////////////////////////////////

input_t *create_input(void);
void destroy_input(input_t *input);
void process_input(window_t *window, input_t *input);


view_t *create_view(sfVector2f player_pos, int size, float zoom, game_t *game);
sfVector2f global_to_view(sfVector2f pos, view_t *view);
sfVector2f global_to_view_fx(sfVector2f pos, view_t *view);
sfVector2f global_to_view_mouse(sfVector2f pos, view_t *view);


#endif