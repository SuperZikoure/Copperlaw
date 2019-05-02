/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** assets_paths
*/

#include "dialogues.h"
#include "macros.h"

static sfSprite *create_dialogue_canvas(void)
{
    sfSprite *canvas = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(texture_path, NULL);

    if (!canvas || !texture)
        return NULL;
    sfSprite_setTexture(canvas, texture, sfTrue);
    sfSprite_setScale(canvas, V2F(.62, .45));
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
