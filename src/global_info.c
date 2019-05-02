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
    {{0, 100, MAIN_MENU}, "play", put_fs},
    {{5, 140, MAIN_MENU}, "skill", res_plus},
    {{10, 180, MAIN_MENU}, "help", res_moins},
    {{15, 220, MAIN_MENU}, "exit", exit_game}
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
    "assets/test2.png"
};

const info_anim_t anim_info[ANIM_AMOUNT] = {
    {{11, 12}, {32, 32}, "assets/anims/can_talk.png"}
};

const info_npc_t npc_info[NPC_AMOUNT] = {
    {{592, 416}, {12, 8}, "assets/npc/sheriff.png", 0, 2},
    {{320, 400}, {60, 10}, "assets/npc/blacksmith.png", 0, 1},
};