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
    {{50, 147}, 0, MAIN_MENU, "newgame", swap_main_menu_to_game},
    {{50, 179}, 0, MAIN_MENU, "loadgame", swap_main_menu_to_game},
    {{50, 211}, 0, MAIN_MENU, "option", swap_main_menu_to_option},
    {{50, 243}, 0, MAIN_MENU, "help", exit_game},
    {{50, 275}, 0, MAIN_MENU, "credits", exit_game},
    {{50, 307}, 0, MAIN_MENU, "exit", exit_game},
    {{85, 162}, 0, OPTIONS, "fullscreen", change_fullscreen_mode},
    {{325, 207}, 0, OPTIONS, "res_plus", icr_resolution},
    {{360, 207}, 0, OPTIONS, "res_less", dcr_resolution},
    {{85, 246}, 0, OPTIONS, "sound", change_sound},
    {{30, 298}, 0, OPTIONS, "back", swap_option_to_main_menu}
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
    "assets/test1.png",
    "assets/test2.png",
    "assets/scenes/main_menu/sky.png",
    "assets/scenes/main_menu/bg.png",
    "assets/scenes/main_menu/logo.png",
    "assets/scenes/menu/selected.png",
    "assets/scenes/menu/not_selected.png",
    "assets/scenes/option/logo.png",
    "assets/scenes/option/resolution.png",
    "assets/buttons/option_hover.png"
};

const info_anim_t anim_info[ANIM_AMOUNT] = {
    {{11, 12}, {32, 32}, "assets/anims/can_talk.png"},
    {{5, 8}, {128, 128}, "assets/scenes/main_menu/player.png"}
};

const info_npc_t npc_info[NPC_AMOUNT] = {
    {{592, 416}, {12, 8}, "assets/npc/sheriff.png", 0, 2},
    {{320, 400}, {60, 10}, "assets/npc/blacksmith.png", 0, 1},
};