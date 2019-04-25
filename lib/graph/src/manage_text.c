/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** text.c
*/

#include <stdlib.h>
#include "graph.h"

text_t *create_text(int fontsize, char *font, window_t *window)
{
    text_t *text = malloc(sizeof(text_t));

    if (!text)
        return (NULL);
    text->window = window;
    text->text = sfText_create();
    text->font = sfFont_createFromFile(font);
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, fontsize);
    return (text);
}

void display_text(char *str, sfVector2f pos, text_t *text)
{   
    if (!text)
        return;
    sfText_setString(text->text, str);
    sfText_setPosition(text->text, pos);
    sfRenderWindow_drawText(text->window->window, text->text, NULL);
}

void destroy_text(text_t *text)
{
    if (!text)
        return;
    sfText_destroy(text->text);
    sfFont_destroy(text->font);
    free(text);
}