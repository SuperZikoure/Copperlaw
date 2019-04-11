/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** assets_paths
*/

#include "dialogues.h"
#include "macros.h"
/* macros.h useless */

const char *canvas_text_path = "";

static sfSprite *create_dialogue_canvas(void)
{
    sfSprite *canvas = sfSprite_create();
    sfTexture *canvas_text = sfTexture_createFromFile(canvas_text_path, NULL);

    if (!canvas || !canvas_text)
        return NULL;
    sfSprite_setTexture(canvas, canvas_text, sfFalse);
    sfSprite_setPosition(canvas, V2F(0, 0));
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
