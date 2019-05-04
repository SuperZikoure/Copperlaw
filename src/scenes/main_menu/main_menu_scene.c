/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** main_menu_scene
*/

#include "my_rpg.h"
#include "macros.h"

static sfText *init_skip_text(game_t *game)
{
    sfText *text = quick_text_create(30, "assets/dialogues/font.ttf");
    if (!text)
        return NULL;
    sfText_setScale(text, V2F(.5, .5));
    sfText_setPosition(text, GTV(560, 380));
    sfText_setString(text, "Click to skip...");
    return text;
}

static int change_square_alpha(void)
{
    static unsigned char color = 255;
    static size_t frames = 0;

    sfSprite_setColor(get_image(BIG_SQUARE)->sprite, COLOR(0, 0, 0, color));
    frames += get_delta();
    if (frames < 6)
        return 0;
    frames -= 6;
    color -= 1 * get_delta();
    if (color <= 1 * get_delta()) {
        color = 0;
        return 1;
    }
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
    pos -= get_delta() / 2.0;
    if (pos <= -2880)
        pos = 0;
    set_parallax_pos(pos);
}

static bool display_intro(game_t *game, sfText *text)
{
    bool is_ended = false;
    
    if (change_square_alpha())
        is_ended = true;
    display_image(get_image(BIG_SQUARE), GTV(0, 0));
    sfRenderWindow_drawText(WINDOW->window, text, NULL);
    return !is_ended;
}

int main_menu_scene(game_t *game)
{
    static bool intro = true;
    static sfText *text = NULL;

    if (!text) {
        text = init_skip_text(game);
        if (!text)
            return -1;
    }
    display_menu(game);
    if (MOUSE_PRESSED(sfMouseLeft))
        intro = false;
    if (intro) {
        intro = display_intro(game, text);
    } else {
        display_image(get_image(MENU_LOGO), GTV(0, 0));
        show_scene_buttons(game);
    }
    display_cursor(game);
    return 0;
}
