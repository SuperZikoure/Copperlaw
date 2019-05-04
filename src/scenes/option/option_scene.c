/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** main_menu_scene
*/

#include "my_rpg.h"
#include "macros.h"

static int analyse_main_menu_events(game_t *game, input_t *input)
{
    if (KEY_PRESSED(ESCAPE_KEY))
        return swap_option_to_main_menu(game, 0);
    return 0;
}

static void display_menu(game_t *game)
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
    display_image(get_image(OPTION_LOGO), GTV(0, 0));
    pos -= get_delta() / 2.0;
    if (pos <= -2880)
        pos = 0;
    set_parallax_pos(pos);
}

int option_scene(game_t *game)
{
    if (analyse_main_menu_events(game, game->input))
        return 1;
    display_menu(game);
    display_image(get_image(OPTION_RESOLUTION), GTV(85, 204));
    display_image(get_image(OPTION_OPTION), GTV(310, 115));
    show_scene_buttons(game);
    display_cursor(game);
    return 0;
}
