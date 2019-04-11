/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** macros
*/

#ifndef MACROS_H_
#define MACROS_H_

#include <SFML/Graphics.h>

#define V2F(x, y) (sfVector2f){x, y}
#define V2I(x, y) (sfVector2i){x, y}
#define V2U(x, y) (sfVector2u){x, y}
#define V3F(x, y, z) (sfVector2f){x, y, z}

#define DESTROY_SPRITE_TEXTURE(s) \
            sfTexture_destroy((sfTexture *) sfSprite_getTexture(s));

#endif /* !MACROS_H_ */
