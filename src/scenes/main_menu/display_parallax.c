/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_parallax
*/

#include "my_rpg.h"
#include "macros.h"

void display_parallax(game_t *game)
{
    float pos = get_parallax_pos();
    float color = sin((2880 + (pos - 400)) / (720 + 192)) * 255;
    sfColor test = {ABS(color), ABS(color), ABS(color), 255};

    if (color < 50 || color > 255)
        color = color < 50 ? 50 : 255;
    test = COLOR(ABS(color), ABS(color), ABS(color), 255);
    sfSprite_setColor(get_image(MENU_BG)->sprite, test);
    sfSprite_setColor(get_anim(MENU_PLAYER)->sheet->sprite, test);
    display_image(get_image(MENU_SKY), GTV(pos, 0));
    pos += 2880;
    display_image(get_image(MENU_SKY), GTV(pos, 0));
    pos -= 2880;
    display_image(get_image(MENU_BG), GTV(0, 0));
    display_anim(get_anim(MENU_PLAYER), GTV(445, 252));
    pos -= get_delta() / 2.0;
    if (pos <= -2880)
        pos = 0;
    set_parallax_pos(pos);
}
