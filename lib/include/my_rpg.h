/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** my_rpg.h
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#include <math.h>
#include "graph.h"
#include "inventory.h"
#include "particle.h"
#include "my.h"

#define BUTTON_PATH ("assets/buttons/")

#define TOTAL_COINS_ON_MAP (100)

#define ZOOM 1.5
#define VIEW_SIZE_X (480 * ZOOM) //720
#define VIEW_SIZE_Y (270 * ZOOM) //405
#define SIZE 7

#define PLAYER_BALLS 200
#define MONSTER_BALLS 25

#define MONSTER_AMOUNT 15;

#define C_SIZE 16

#define BUTTON_AMOUNT 31

#define TP_AMOUNT 21

#define DEFAULT_SCREENSIZE 4
#define RESOLUTIONS 6

#define KEY_PRESSED(c) (input->keys[c]->pressed)
#define KEY_HELD(c) (input->keys[c]->held)

#define MOUSE_PRESSED(c) (mouse_pressed_once(c))
#define MOUSE_HELD(c) (sfMouse_isButtonPressed(c))

#define ANIM(i) anim_info[i]
#define F_ANIM(i) create_anim(ANIM(i).fps, ANIM(i).size, ANIM(i).path, window)

#define WINDOW game->window
#define VIEW game->view
#define CURSOR game->gui->cursor
#define GUI game->gui
#define PLAYER game->player
#define G_INVENTORY game->inventory
#define RES game->option.resolution
#define FS game->option.fullscreen
#define SOUND game->option.sound

#define AMOUNT_STR(i) my_itoa(get_amount(i, G_INVENTORY))

#define STATS(i) player->stats[i]

#define FSTR(i) my_float_to_str(i)
#define CAT(i, j) my_strcat(i, j)

#define CAT_NOFREE(i, j) my_strcat_no_free(i, j)

#define DISP_STATS(i, j) CAT(CAT_NOFREE(FSTR(STATS(i)), "/") ,FSTR(STATS(j)))

typedef struct game_s game_t;
typedef struct info_button_s info_button_t;
typedef struct info_npc_s info_npc_t;
typedef struct info_anim_s info_anim_t;
typedef struct info_tp_s info_tp_t;
typedef struct info_music_s info_music_t;
typedef int (*scene_swap_t)(game_t *);
typedef void (*item_function_t)(game_t *);

struct info_anim_s
{
    sfVector2f fps;
    sfVector2i size;
    char *path;
};

struct info_tp_s
{
    sfVector3f pos;
    sfVector3f dest;
    bool is_door;
};

struct info_npc_s
{
    sfVector2f pos;
    sfVector2f fps;
    char *path;
    int map;
    int dialogue;
};

struct info_item_s
{
    int hp;
    int mp;
    int sp;
};

struct info_music_s
{
    char *main_path;
    char *cover_path;
};

enum enum_item_e
{
    EMPTY,
    ELIXIR_OF_LIFE,
    BEER,
    RUM,
    SNAKE_VENOM,
    FIELD_RATIO,
    CACTUS_JUICE,
    TEQUILA,
    ETHANOL,
    ITEM_AMOUNT
};

enum enum_text_e
{
    SMALL_TEXT,
    BIG_TEXT,
    CREDIT_TEXT,
    TEXT_AMOUNT
};

enum musics_ids_e {
    MAIN_MENU_MUSIC,
    VILLAGE_MUSIC,
    WILD_MUSIC,
    MUSIC_AMOUT
};

enum enum_map_e {
    VILLAGE_MAP,
    WILD_MAP,
    SHERIFF_MAP,
    SALOON_MAP,
    HOUSE_MAP,
    MAP_AMOUNT
};

enum enum_scene_e {
    MAIN_MENU,
    OPTIONS,
    GAME,
    INVENTORY,
    HOW_TO_PLAY,
    CREDIT,
    MENU,
    SCENE_NB
};

struct info_button_s
{
    sfVector2f pos;
    int option;
    enum enum_scene_e scene;
    char *path;
    int (*trigger)(game_t *, int);
};

enum zone_ids {
    INTRO,
    WEAPON,
    VILLAGE,
    ZONE_NB
};

#define DELETE -1

enum enum_images_e {
    TRAIL_1,
    TRAIL_2,
    MENU_SKY,
    MENU_BG,
    MENU_LOGO,
    BUTTON_SELECTED,
    BUTTON_NOT_SELECTED,
    OPTION_LOGO,
    OPTION_RESOLUTION,
    OPTION_OPTION,
    BIG_SQUARE,
    PAUSE_BG,
    BUTTON_NOT_SELECTED_2,
    INVENTORY_SELECTED,
    STATS_SELECTED,
    SKILLS_SELECTED,
    HUD,
    HUD_ITEMS,
    ITEMS,
    HOWTOPLAY_IMG,
    WHITE_BALL,
    GREEN_BALL,
    BLUE_BALL,
    CREDIT_IMG,
    IMAGE_AMOUNT
};

enum enum_anims_e {
    CAN_TALK,
    MENU_PLAYER,
    COIN,
    LIFE_BAR,
    MANA_BAR,
    SP_BALL,
    ANIM_AMOUNT
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
    NOTE,
    BARMAN,
    VILLAGER,
    OLD_COWBOY,
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
    ATTACK_COOLDOWN,
    ATTACK_RANGE,
    DAMAGE,
    DEFENSE,
    CURRENT_XP,
    MAX_XP,
    LVL,
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

enum enum_class_e {
    NO_CLASS,
    REVOLVER,
    SHOTGUN,
    CLASS_AMOUNT
};

extern const sfVideoMode window_size[RESOLUTIONS];
extern const char *image_path[IMAGE_AMOUNT];
extern const info_anim_t anim_info[ANIM_AMOUNT];
extern const info_button_t info[BUTTON_AMOUNT];
extern const sfKeyCode input_key[KEY_NB];
extern const info_npc_t npc_info [NPC_AMOUNT];
extern const info_tp_t tp_info[TP_AMOUNT];
extern const char* font_path[TEXT_AMOUNT];
extern const int font_size[TEXT_AMOUNT];
extern const info_music_t music_paths[MUSIC_AMOUT];
extern const char* desc_item[ITEM_AMOUNT];
extern const int item_prices[ITEM_AMOUNT];

typedef struct button_s
{
    int (*trigger)(game_t *, int);
    int option;
    char *name;
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
    void *parent;
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
    unsigned short resolution;
    bool fullscreen;
    bool sound;
} option_t;

typedef struct map_s {
    char **map;
    sfVector2i size;
    image_t *bg;
    image_t *fg;
} map_t;

typedef struct coin_s
{
    sfVector2f pos;
    sfVector2f vel;
    int exist;
    int attract;
} coin_t;

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
    int skill;
    col_t col;
} ball_t;

typedef struct monster_s {
    sfVector2f pos;
    sfVector2f speed;
    sfVector2f bump;
    int aggro;
    image_t *normal;
    image_t *hit;
    int hp;
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
    ball_t *balls[PLAYER_BALLS];
    col_t col;
    int moving;
    int level_up_display;
    int class;
} player_t;

struct game_s {
    window_t *window;
    view_t *view;
    gui_t *gui;
    input_t *input;
    option_t option;
    player_t *player;
    inventory_t *inventory;
    int current_map;
    map_t *maps[MAP_AMOUNT];
    npc_t *npc[NPC_AMOUNT];
    text_t *texts[TEXT_AMOUNT];
    music_t *music;
    coin_t **coins;
    monster_t *monsters[5];
    int money;
    struct dialogue_s *dialogue;
    sfVector2i mouse_pos;
    int exit;
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
int text_intersect(sfText *text, image_t *image);
int point_intersect(image_t *img, float x, float y);
int image_intersect(image_t *img1, image_t *img2);


/* utiles */
float get_distance(sfVector2f p1, sfVector2f p2);


/* create_game.c */
game_t create_game(void);
int destroy_game(game_t *game);

/* BUTTONS */
button_t *create_button(const info_button_t *info, view_t *view);
void show_scene_buttons(game_t *game);
sfBool mouse_pressed_once(int mouse_button);
button_t *find_button(game_t *game, char *name, enum enum_scene_e scene);

/// SCENES ///

/* TRANSITIONS */
int swap_game_to_menu(game_t *game, int option);
int swap_menu_to_game(game_t *game, int option);
int swap_main_menu_to_game(game_t *game, int option);
int swap_menu_to_inventory(game_t *game, int option);
int swap_main_menu_to_option(game_t *game, int option);
int swap_option_to_main_menu(game_t *game, int option);
int swap_main_menu_to_howtoplay(game_t *game, int option);
int swap_howtoplay_to_main_menu(game_t *game, int option);
int swap_main_menu_to_credits(game_t *game, int option);
int swap_credits_to_main_menu(game_t *game, int option);
int swap_menu_to_main_menu(game_t *game, int option);

/* GAME */
int game_scene(game_t *game);
void display_cursor_trail(game_t *game, sfVector2f view_pos[4]);
void compute_game_interactions(game_t *game);
int compute_dialogues_interactions(game_t *game);
void analyse_movement_keys(input_t *input, player_t *player);
void set_player_position(game_t *game);
void update_game_gui(game_t *game);
void player_management(game_t *game);
void barman_shop(game_t *game);
void cowboy_shop(game_t *game);
void blacksmith_shop(game_t *game);

/* FIRE BALL */
void display_balls(ball_t *balls[PLAYER_BALLS]);
void check_input_fire(game_t *game, sfVector2f dir);

/* MAIN MENU */
int main_menu_scene(game_t *game);

/* MENU */
int menu_scene(game_t *game);

/* INVENTORY */
int inventory_scene(game_t *game);

/* OPTION */
int option_scene(game_t *game);

/* HOW_TO_PLAY */
int how_to_play_scene(game_t *game);

/* CREDITS */
int credit_scene(game_t *game);

/* CREDIT */
int credit(game_t *game);

/* maps/create_map.c */
map_t *create_map(char *filepath, window_t *window);

/* create_player.c */
player_t *create_player(game_t *game);

/* movement */
int get_map_pos(int pos);
void change_anim(player_t *player);
void move_player(player_t *player, char dir);
void slow_down_player(player_t *player);
void set_idle_animation(game_t *game);
void dash(input_t *input, sfVector2f *dash, sfVector2f vel, sfVector2f dir);

/* manage_collisions.c */
void compute_col(col_t *col, int current_map);

/* fetch_image.c */
int fill_image(window_t *window);
image_t *get_image(int index);

/* fetch_anim.c */
int fill_anim(window_t *window);
void update_fetch_anim();
anim_t *get_anim(int index);

/* fetch_oldest_dialogue_response.c */
int get_response(void);
void store_response(int choice);

/* display_mobs.c */
void display_mobs(game_t *game);

/* update_stats.c */
void update_stats(player_t *player);

/* BUTTON FUNCTIONS */
int exit_game(game_t *game, int option);
int change_fullscreen_mode(game_t *game, int option);
int icr_resolution(game_t *game, int option);
int dcr_resolution(game_t *game, int option);
int change_sound(game_t *game, int option);
int use_item(game_t *game, int option);

void use_elixir(game_t *game);
void use_beer(game_t *game);
void use_rum(game_t *game);
void use_snakevenom(game_t *game);
void use_fieldratio(game_t *game);
void use_cactusjuice(game_t *game);
void use_tequila(game_t *game);
void use_ethanol(game_t *game);

/* SCREESHOT */
#define SCREENSHOT_FILENAME_MAX 10
int do_screenshot(window_t *window);

/* PARALLAX (main_menu, option, how2play) */
void display_parallax(game_t *game);
float get_parallax_pos(void);
void set_parallax_pos(float value);

/* DOOR SOUND */
sound_t *get_door_sound(void);
void destroy_door_sound(void);

////////////////////////////////////

input_t *create_input(void);
void destroy_input(input_t *input);
void process_input(input_t *input);

view_t *create_view(sfVector2f player_pos, int size, float zoom, game_t *game);
sfVector2f global_to_view(sfVector2f pos, view_t *view);
sfVector2f global_to_view_fx(sfVector2f pos, view_t *view);
sfVector2f global_to_view_mouse(sfVector2f pos, view_t *view);

/* coins */

coin_t *init_coin(void);
void manage_coins(coin_t **coins, sfVector2f pos, game_t *game);
void drop_coin(sfVector2f pos, coin_t **coins, int mode);

monster_t *create_monster(sfVector2f pos, window_t *window);
void manage_monster(monster_t *monster, ball_t *balls[PLAYER_BALLS],
                    sfVector2f pos);

#endif
