/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** input.c
*/

#include <stdlib.h>
#include "graph.h"

keypress_t *create_key(sfKeyCode key)
{
    keypress_t *this_key = malloc(sizeof(keypress_t));

    this_key->held = 0;
    this_key->pressed = 0;
    this_key->key = key;
    return (this_key);
}

input_t *create_input(void)
{
    input_t *input = malloc(sizeof(input_t));

    input->up = create_key(sfKeyZ);
    input->down = create_key(sfKeyS);
    input->left = create_key(sfKeyQ);
    input->right = create_key(sfKeyD);
    input->escape = create_key(sfKeyEscape);
    input->space = create_key(sfKeySpace);
    return (input);
}

void process_key(keypress_t *key)
{
    if (sfKeyboard_isKeyPressed(key->key) == sfTrue && key->held == 0)
        key->pressed = 1;
    else
        key->pressed = 0;
    if (sfKeyboard_isKeyPressed(key->key) == sfTrue)
        key->held = 1;
    else
        key->held = 0;
}

void process_input(window_t *window, input_t *input)
{
    while (sfRenderWindow_pollEvent(window->window,
    &window->event)) {
        window->width = sfRenderWindow_getSize(window->window).x;
        window->height = sfRenderWindow_getSize(window->window).y;
        if (window->event.type == sfEvtClosed)
            sfRenderWindow_close(window->window);
        process_key(input->up);
        process_key(input->down);
        process_key(input->left);
        process_key(input->right);
        process_key(input->space);
        process_key(input->escape);
    }
}

void destroy_input(input_t *input)
{
    free(input->up);
    free(input->down);
    free(input->left);
    free(input->right);
    free(input->space);
    free(input->escape);
    free(input);
}