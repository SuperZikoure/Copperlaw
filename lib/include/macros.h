/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** macros
*/

#ifndef MACROS_H_
#define MACROS_H_

#include <SFML/Graphics.h>
#include "my_string.h"

#define V2F(x, y) (sfVector2f){x, y}
#define V2I(x, y) (sfVector2i){x, y}
#define V2U(x, y) (sfVector2u){x, y}
#define V3F(x, y, z) (sfVector2f){x, y, z}
#define COLOR(r, g, b, a) (sfColor){r, g, b, a}

#define DESTROY_SPRITE_TEXTURE(s) \
            sfTexture_destroy((sfTexture *) sfSprite_getTexture(s));
#define DESTROY_TEXT_FONT(t) sfFont_destroy((sfFont *) sfText_getFont(t))

#define STRLEN_EQ(s1, s2) (my_strlen(s1) == my_strlen(s2))
#define STR_EQ(s1, s2) (!my_strcmp(s1, s2))

#define IS_TEXT_ENDED(d) STRLEN_EQ(d->script, d->said)

#define SET_SELECTED_CHOISE_COLOR(s, c) \
            sfText_setColor(s->texts[s->selected].text, c)

#endif /* !MACROS_H_ */
