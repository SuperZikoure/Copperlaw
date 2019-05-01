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

/* SFML */
#define V2F(x, y) (sfVector2f){x, y}
#define V2I(x, y) (sfVector2i){x, y}
#define V2U(x, y) (sfVector2u){x, y}
#define V3F(x, y, z) (sfVector3f){x, y, z}
#define COLOR(r, g, b, a) (sfColor){r, g, b, a}
#define IRECT(l, t, w, h) (sfIntRect){l, t, w, h}

#define DESTROY_SPRITE_TEXTURE(s) \
            sfTexture_destroy((sfTexture *) sfSprite_getTexture(s));
#define DESTROY_TEXT_FONT(t) sfFont_destroy((sfFont *) sfText_getFont(t))


/* MATHS */
#define DEG(c) (c * (180 / M_PI))
#define ABS(a) ((a < 0) ? -a : a)
#define CAM(a, b, c) ((c * a + b) / (c + 1))

/* STRING STUFF */
#define STRLEN_EQ(s1, s2) (my_strlen(s1) == my_strlen(s2))
#define STR_EQ(s1, s2) (!my_strcmp(s1, s2))


/* used to know if a dialogue has been fully displayed or not */
#define IS_TEXT_ENDED(d) STRLEN_EQ(d->script, d->said)

/* PLAYER MOVEMENT */
#define MOVES_UP(dir) (dir & DIR_UP)
#define MOVES_DOWN(dir) (dir & DIR_DOWN)
#define MOVES_RIGHT(dir) (dir & DIR_RIGHT)
#define MOVES_LEFT(dir) (dir & DIR_LEFT)

#endif /* !MACROS_H_ */
