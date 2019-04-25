/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** manage_inputs.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "my_rpg.h"

input_t *create_input(void)
{
    input_t *input = malloc(sizeof(input_t));

    for (int i = 0; i < KEY_AMOUNT; i++)
        input->keys[i] = create_key(input_key[i]);
    return (input);
}

void process_input(window_t *window, input_t *input)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        window->width = sfRenderWindow_getSize(window->window).x;
        window->height = sfRenderWindow_getSize(window->window).y;
        if (window->event.type == sfEvtClosed)
            sfRenderWindow_close(window->window);
        for (int i = 0; i < KEY_AMOUNT; i++)
            process_key(input->keys[i]);
    }
}

void destroy_input(input_t *input)
{
    for (int i = 0; i < KEY_AMOUNT; i++)
        free(input->keys[i]);
    free(input);
}
