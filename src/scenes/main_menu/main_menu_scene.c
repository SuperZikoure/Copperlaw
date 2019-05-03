/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** main_menu_scene
*/

#include "my_rpg.h"
#include "macros.h"
#include <math.h>
#include <stdio.h>

static void display_menu(game_t *game)
{
    static float pos = 0;
    float color = sin((2880 + (pos - 400)) / (720 + 192)) * 255;
    sfColor test = {ABS(color), ABS(color), ABS(color), 255};

    if (color > 255)
        color = 255;
    else if (color < 50)
        color = 50;
    test = (sfColor){ABS(color), ABS(color), ABS(color), 255};
    sfSprite_setColor(get_image(MENU_BG)->sprite, test);
    sfSprite_setColor(get_anim(MENU_PLAYER)->sheet->sprite, test);
    display_image(get_image(MENU_SKY), GTV(pos, 0));
    pos += 2880;
    display_image(get_image(MENU_SKY), GTV(pos, 0));
    pos -= 2880;
    display_image(get_image(MENU_BG), GTV(0, 0));
    display_anim(get_anim(MENU_PLAYER), GTV(450, 250));
    display_image(get_image(MENU_LOGO), GTV(0, 0));
    pos -= get_delta() / 2.0;
    if (pos <= -2880)
        pos = 0;
}

int main_menu_scene(game_t *game)
{
    display_menu(game);
    show_scene_buttons(game);
    display_cursor(game);
    return 0;
}
