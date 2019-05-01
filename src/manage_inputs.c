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

    if (!input)
        return NULL;
    for (int i = 0; i < KEY_NB; i++) {
        input->keys[i] = create_key(input_key[i]);
        if (!input->keys[i])
            return NULL;
    }
    return (input);
}

void process_input(input_t *input)
{
    for (int i = 0; i < KEY_NB; i++)
        process_key(input->keys[i]);
}

void destroy_input(input_t *input)
{
    for (int i = 0; i < KEY_NB; i++)
        free(input->keys[i]);
    free(input);
}
