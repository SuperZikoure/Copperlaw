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
    {{50, 250}, 0, MAIN_MENU, "help", exit_game},
    {{50, 284}, 0, MAIN_MENU, "credits", exit_game},
    {{50, 318}, 0, MAIN_MENU, "exit", exit_game},
    {{85, 162}, 0, OPTIONS, "fullscreen", change_fullscreen_mode},
    {{325, 207}, 0, OPTIONS, "res_plus", icr_resolution},
    {{360, 207}, 0, OPTIONS, "res_less", dcr_resolution},
    {{85, 246}, 0, OPTIONS, "sound", change_sound},
    {{5, 298}, 0, OPTIONS, "back", swap_option_to_main_menu},
    {{5, 260}, 0, MENU, "resume", swap_menu_to_game},
    {{5, 312}, 0, MENU, "save", swap_menu_to_game},
    {{5, 364}, 0, MENU, "exit", exit_game},
    {{5, 63}, 0, MENU, "inventory", swap_menu_to_inventory},
    {{5, 115}, 0, MENU, "skills", swap_menu_to_skills}
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
    "assets/scenes/menu/skills.png"
};

const info_anim_t anim_info[ANIM_AMOUNT] = {
    {{11, 12}, {32, 32}, "assets/anims/can_talk.png"},
    {{5, 8}, {128, 128}, "assets/scenes/main_menu/player.png"}
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
    {{592, 416}, {12, 8}, "assets/npc/sheriff.png", 0, 2},
    {{320, 400}, {60, 10}, "assets/npc/blacksmith.png", 0, 1},
};