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

#define PLAYER_BALLS 200
#define MONSTER_BALLS 25

#define C_SIZE 16

#define BUTTON_AMOUNT 4

#define MAP_AMOUNT 1

#define DEFAULT_SCREENSIZE 4
#define RESOLUTIONS 6

#define KEY_PRESSED(c) (input->keys[c]->pressed)
#define KEY_HELD(c) (input->keys[c]->held)

#define MOUSE_PRESSED(c) (mouse_pressed_once(c))
#define MOUSE_HELD(c) (sfMouse_isButtonPressed(c))

#define WINDOW game->window
#define VIEW game->view
#define CURSOR game->gui->cursor
#define GUI game->gui
#define PLAYER game->player

#define RES game->option.resolution
#define FS game->option.fullscreen

typedef struct game_s game_t;
typedef struct info_button_s info_button_t;
typedef struct info_npc_s info_npc_t;

struct info_button_s
{
    sfVector3f pos;
    char *path;
    void (*trigger)(game_t*);
};

struct info_npc_s
{
    sfVector2f pos;
    sfVector2f fps;
    char *path;
    int map;
};

enum enum_scene_e {
    MAIN_MENU,
    OPTIONS,
    GAME,
    INVENTORY,
    SKILLS,
    STATS,
    MENU,
    SCENE_NB
};

enum zone_ids {
    INTRO,
    VILLAGE,
    ZONE_NB
};

#define DELETE -1

enum enum_images_e {
    TRAIL_1,
    TRAIL_2,
    IMAGE_AMOUNT
};

enum direction_e {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

enum bin_directions {
    DIR_UP = 0b0001,
    DIR_DOWN = 0b0010,
    DIR_RIGHT = 0b0100,
    DIR_LEFT = 0b1000
};

enum npc_list {
    SHERIFF,
    BLACKSMITH,
    NPC_AMOUNT
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
    SKILL_2_COOLDOWN,
    STATS_AMOUNT
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
    SKILL_3_KEY,
    SCREENSHOT_KEY,
    KEY_NB
};

enum cursor_modes {
    CURSOR_BASE,
    CURSOR_IDLE,
    CURSOR_INSPECT,
    CURSOR_BUILD,
    CURSOR_MODES_NB
};

extern const sfVideoMode window_size[RESOLUTIONS];
extern const char *image_path[IMAGE_AMOUNT];
extern const info_button_t info[BUTTON_AMOUNT];
extern const sfKeyCode input_key[KEY_NB];
extern const info_npc_t npc_info [NPC_AMOUNT];

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
    enum enum_scene_e scene;
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
    void *parent;
} gui_t;

typedef struct view_s {
    window_t *window;
    sfView *camera;
    sfFloatRect pos;
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
    keypress_t *keys[KEY_NB];
} input_t;

typedef struct npc_s {
    sfVector2f pos;
    anim_t *display;
    int map;
} npc_t;

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
    npc_t *npc[NPC_AMOUNT];
    sfVector2i mouse_pos;
    int frames;
    int exit;
    int scene;
};

/* main game functions */
void game_loop(game_t *game);
int analyse_events(game_t *game);

/* SCENE SYSTEM */
int (*get_scene(void))(game_t *);
enum enum_scene_e get_scene_id(void);
void change_scene(enum enum_scene_e id);

/* DELTA */
size_t get_delta(void);
int start_clock(void);
void start_new_frame(void);

/* GUI */
gui_t *create_gui(view_t *view);
void display_cursor(game_t *game);

/* manage_intersections.c */
int point_intersect(image_t *img, float x, float y);
int image_intersect(image_t *img1, image_t *img2);

/* create_game.c */
game_t create_game(void);

/* BUTTONS */
button_t *create_button(char *path, sfVector3f pos, view_t *view,
                                void (*trigger)(game_t *));
void show_scene_buttons(game_t *game);
sfBool mouse_pressed_once(int mouse_button);

/// SCENES ///

/* TRANSITIONS */
int swap_game_to_menu(game_t *game);
int swap_menu_to_game(game_t *game);
int swap_main_menu_to_game(game_t *game);

/* GAME */
int game_scene(game_t *game);
void display_cursor_trail(game_t *game, sfVector2f view_pos[4]);
void compute_game_interactions(game_t *game);
void analyse_movement_keys(input_t *input, player_t *player);
void set_player_position(game_t *game);
void update_game_gui(game_t *game);
/* FIRE BALL */
void display_balls(ball_t *balls[PLAYER_BALLS]);
void fire_ball(sfVector2f pos, ball_t *balls[PLAYER_BALLS], sfVector2f dir);

/* MAIN MENU */
int main_menu_scene(game_t *game);

/* MENU */
int menu_scene(game_t *game);


/* maps/create_map.c */
map_t *create_map(char *filepath, window_t *window);

/* create_player.c */
player_t *create_player(game_t *game);

/* movement */
void change_anim(player_t *player);
void move_player(player_t *player, char dir);
void set_idle_animation(game_t *game);
void dash(input_t *input, sfVector2f *dash, sfVector2f vel, sfVector2f dir);

/* manage_collisions.c */
void compute_col(col_t *col, int current_map);

/* fetch_image.c */
int fill_image(window_t *window);
image_t *get_image(int index);

/* display_mobs.c */
void display_mobs(game_t *game);

/* BUTTON FUNCTIONS */
void put_game_scene(game_t *game);
void exit_game(game_t *game);
void res_moins(game_t *game);
void res_plus(game_t *game);
void put_fs(game_t *game);

/* SCREESHOT */
#define SCREENSHOT_FILENAME_MAX 10
int do_screenshot(window_t *window);

////////////////////////////////////

input_t *create_input(void);
void destroy_input(input_t *input);
void process_input(input_t *input);

view_t *create_view(sfVector2f player_pos, int size, float zoom, game_t *game);
sfVector2f global_to_view(sfVector2f pos, view_t *view);
sfVector2f global_to_view_fx(sfVector2f pos, view_t *view);
sfVector2f global_to_view_mouse(sfVector2f pos, view_t *view);

#endif
