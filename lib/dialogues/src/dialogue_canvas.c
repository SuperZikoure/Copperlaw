/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** assets_paths
*/

#include "dialogues.h"
#include "macros.h"
/* macros.h useless */

static sfSprite *create_dialogue_canvas(void)
{
    sfSprite *canvas = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(texture_path, NULL);

    if (!canvas || !texture)
        return NULL;
    sfSprite_setTexture(canvas, texture, sfFalse);
    sfSprite_setPosition(canvas, V2F(100, 450));
    sfSprite_setColor(canvas, COLOR(0, 0, 0, 255));
    return canvas;
}

sfSprite *fetch_dialogue_canvas(void)
{
    static sfSprite *canvas = NULL;

    if (!canvas)
        canvas = create_dialogue_canvas();
    return canvas;
}

void destroy_dialogue_canvas(void)
{
    sfSprite *canvas = fetch_dialogue_canvas();

    if (!canvas)
        return;
    DESTROY_SPRITE_TEXTURE(canvas);
    sfSprite_destroy(canvas);
}
