/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** info.c
*/

#include "my_rpg.h"
#include "macros.h"

const sfVideoMode window_size[RESOLUTIONS] = {
    {640, 360, 32},
    {800, 450, 32},
    {1024, 576, 32},
    {1280, 720, 32},
    {1600, 900, 32},
    {1920, 1080, 32}
};

const info_button_t info[BUTTON_AMOUNT] = {
    {{50, 148}, 0, MAIN_MENU, "newgame", swap_main_menu_to_game},
    {{50, 181}, 0, MAIN_MENU, "loadgame", swap_main_menu_to_game},
    {{50, 216}, 0, MAIN_MENU, "option", swap_main_menu_to_option},
    {{50, 250}, 0, MAIN_MENU, "help", swap_main_menu_to_howtoplay},
    {{50, 284}, 0, MAIN_MENU, "credits", swap_main_menu_to_credits},
    {{50, 318}, 0, MAIN_MENU, "exit", exit_game},
    {{85, 162}, 0, OPTIONS, "fullscreen", change_fullscreen_mode},
    {{325, 207}, 0, OPTIONS, "res_plus", icr_resolution},
    {{360, 207}, 0, OPTIONS, "res_less", dcr_resolution},
    {{85, 246}, 0, OPTIONS, "sound", change_sound},
    {{5, 298}, 0, OPTIONS, "back", swap_option_to_main_menu},
    {{50, 318}, 0, HOW_TO_PLAY, "back", swap_howtoplay_to_main_menu},
    {{50, 318}, 0, CREDIT, "back", swap_credits_to_main_menu},
    {{5, 208}, 0, MENU, "resume", swap_menu_to_game},
    {{5, 260}, 0, MENU, "save", swap_menu_to_game},
    {{5, 312}, 0, MENU, "quit", swap_option_to_main_menu},
    {{5, 364}, 0, MENU, "exit", exit_game},
    {{5, 63}, 0, MENU, "inventory", swap_menu_to_inventory},
    {{5, 208}, 0, INVENTORY, "resume", swap_menu_to_game},
    {{5, 260}, 0, INVENTORY, "save", swap_menu_to_game},
    {{5, 312}, 0, INVENTORY, "quit", swap_option_to_main_menu},
    {{5, 364}, 0, INVENTORY, "exit", exit_game},
    {{5, 11}, 0, INVENTORY, "stats", swap_game_to_menu},
    {{668, 72}, 1, GAME, "inv_button", use_item},
    {{668, 108}, 2, GAME, "inv_button", use_item},
    {{668, 144}, 3, GAME, "inv_button", use_item},
    {{668, 180}, 4, GAME, "inv_button", use_item},
    {{668, 216}, 5, GAME, "inv_button", use_item},
    {{668, 252}, 6, GAME, "inv_button", use_item},
    {{668, 288}, 7, GAME, "inv_button", use_item},
    {{668, 324}, 8, GAME, "inv_button", use_item}
};

const sfKeyCode input_key[KEY_NB] = {
    sfKeyZ,
    sfKeyD,
    sfKeyS,
    sfKeyQ,
    sfKeyReturn,
    sfKeyEscape,
    sfKeySpace,
    sfKeyE,
    sfKeyA,
    sfKeyTab,
    sfKeyNum1,
    sfKeyNum2,
    sfKeyNum3,
    sfKeyF11
};

const char *image_path[IMAGE_AMOUNT] = {
    "assets/trail1.png",
    "assets/trail2.png",
    "assets/scenes/main_menu/sky.png",
    "assets/scenes/main_menu/bg.png",
    "assets/scenes/main_menu/logo.png",
    "assets/scenes/menu/selected.png",
    "assets/scenes/menu/not_selected.png",
    "assets/scenes/option/logo.png",
    "assets/scenes/option/resolution.png",
    "assets/buttons/option_hover.png",
    "assets/big_square.png",
    "assets/scenes/menu/background.png",
    "assets/scenes/menu/not_selected_inverted.png",
    "assets/scenes/menu/inventory.png",
    "assets/scenes/menu/stats.png",
    "assets/scenes/menu/skills.png",
    "assets/scenes/game/HUD.png",
    "assets/scenes/game/HUD_ITEMS.png",
    "assets/scenes/menu/items.png",
    "assets/scenes/how_to_play/board.png",
    "assets/ball_white.png",
    "assets/ball_green.png",
    "assets/ball_blue.png",
    "assets/scenes/credit/long_board.png"
};

const char *font_path[TEXT_AMOUNT] = {
    "assets/fonts/1.ttf",
    "assets/fonts/2.ttf",
    "assets/fonts/4.ttf",
};

const int font_size[TEXT_AMOUNT] = {
    12,
    10,
    30
};

const info_anim_t anim_info[ANIM_AMOUNT] = {
    {{11, 12}, {32, 32}, "assets/anims/can_talk.png"},
    {{5, 8}, {128, 128}, "assets/scenes/main_menu/player.png"},
    {{10, 12}, {16, 16}, "assets/coin.png"},
    {{48, 0}, {400, 75}, "assets/hp.png"},
    {{32, 0}, {600, 200}, "assets/mp.png"},
    {{11, 0}, {19, 40}, "assets/sp.png"}
};

const info_tp_t tp_info[TP_AMOUNT] = {
    {{35, 26, VILLAGE_MAP}, {4, 11, SHERIFF_MAP}, true},
    {{4, 12, SHERIFF_MAP}, {35, 27, VILLAGE_MAP}, true},
    {{5, 12, SHERIFF_MAP}, {35, 27, VILLAGE_MAP}, true},
    {{3, 32, VILLAGE_MAP}, {5, 9, HOUSE_MAP}, true},
    {{5, 10, HOUSE_MAP}, {3, 33, VILLAGE_MAP}, true},
    {{6, 10, HOUSE_MAP}, {3, 33, VILLAGE_MAP}, true},
    {{24, 11, VILLAGE_MAP}, {8, 15, SALOON_MAP}, true},
    {{25, 11, VILLAGE_MAP}, {8, 15, SALOON_MAP}, true},
    {{7, 16, SALOON_MAP}, {24, 12, VILLAGE_MAP}, true},
    {{8, 16, SALOON_MAP}, {24, 12, VILLAGE_MAP}, true},
    {{9, 16, SALOON_MAP}, {25, 12, VILLAGE_MAP}, true},
    {{39, 0, VILLAGE_MAP}, {96, 96, WILD_MAP}, false},
    {{40, 0, VILLAGE_MAP}, {97, 96, WILD_MAP}, false},
    {{41, 0, VILLAGE_MAP}, {98, 96, WILD_MAP}, false},
    {{42, 0, VILLAGE_MAP}, {99, 96, WILD_MAP}, false},
    {{43, 0, VILLAGE_MAP}, {100, 96, WILD_MAP}, false},
    {{96, 97, WILD_MAP}, {39, 1, VILLAGE_MAP}, false},
    {{97, 97, WILD_MAP}, {40, 1, VILLAGE_MAP}, false},
    {{98, 97, WILD_MAP}, {41, 1, VILLAGE_MAP}, false},
    {{98, 97, WILD_MAP}, {42, 1, VILLAGE_MAP}, false},
    {{100, 97, WILD_MAP}, {43, 1, VILLAGE_MAP}, false}
};

const info_npc_t npc_info[NPC_AMOUNT] = {
    {{215, 64}, {36, 8}, "assets/npc/barman.png", SALOON_MAP, 0},
    {{320, 400}, {60, 10}, "assets/npc/blacksmith.png", VILLAGE_MAP, 1},
    {{592, 416}, {12, 8}, "assets/npc/sheriff.png", VILLAGE_MAP, 2},
    {{14, 69}, {0, 0}, "assets/npc/note.png", SHERIFF_MAP, 3},
    {{1552, 432}, {65, 12}, "assets/npc/old_cowboy.png", WILD_MAP, 4},
    {{92, 68}, {25, 6}, "assets/npc/villager.png", HOUSE_MAP, 5}
};

char *map_paths[MAP_AMOUNT] = {
    "src/data/maps/village",
    "src/data/maps/wild",
    "src/data/maps/sheriff",
    "src/data/maps/saloon",
    "src/data/maps/house"
};

const info_music_t music_paths[MUSIC_AMOUT] = {
    {"assets/musics/main_menu.ogg", NULL}
};

const char *stats_desc[STATS_AMOUNT] = {
    NULL,
    "HP: ",
    NULL,
    "MP: ",
    NULL,
    "SP: ",
    "Speed: ",
    "Dash CD: ",
    "Attack Speed: ",
    "Attack CD: ",
    "Attack Range: ",
    "Damage",
    "Defense",
    "XP",
    NULL,
    "LVL: ",
    "SP Points: "
};

const char *desc_item[ITEM_AMOUNT] = {
    NULL,
    "Elixir of life : Heals 2 HP.",
    "Beer : Heals 4 HP.",
    "Rum : Heals all of your HP",
    "Snake Venom : Gives you 2 SP back.",
    "Field Ratio : Gives you all of your SP back.",
    "Cactus Juice : Gives you all of your MP back.",
    "Tequila : Gives you all of your MP back and 1 SP.",
    "Ethanol : Gives you all of your MP and SP back at the cost of 2 HP."
};

const int item_prices[ITEM_AMOUNT] = {
    -1,
    3,
    6,
    10,
    3,
    10,
    15,
    30,
    35
};
