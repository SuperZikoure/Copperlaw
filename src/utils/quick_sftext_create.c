/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** quick_sftext_create
*/

#include <SFML/Graphics.h>

sfText *quick_text_create(unsigned int char_size, const char *fontpath)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(fontpath);

    if (!text || !font)
        return NULL;
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, char_size);
    return text;
}
