/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** info.c
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "graph.h"
#include "my_rpg.h"

const sfVideoMode window_size[RESOLUTIONS] = {
    {640, 360, 32},
    {800, 450, 32},
    {1024, 576, 32},
    {1280, 720, 32},
    {1600, 900, 32},
    {1920, 1080, 32}
};

const info_button_t info[BUTTON_AMOUNT] = {
    {{0, 100, MENU}, "play", put_fs},
    {{5, 140, MENU}, "skill", res_plus},
    {{10, 180, MENU}, "help", res_moins},
    {{15, 220, MENU}, "exit", exit_game}
};

const sfKeyCode input_key[KEY_AMOUNT] = {
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
    sfKeyNum3
};

const char *image_path[IMAGE_AMOUNT] = {
    "assets/test1.png",
    "assets/test2.png"
};
