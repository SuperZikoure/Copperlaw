/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** input.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

keypress_t *create_key(sfKeyCode key)
{
    keypress_t *this_key = malloc(sizeof(keypress_t));

    this_key->held = 0;
    this_key->pressed = 0;
    this_key->key = key;
    return (this_key);
}

void process_key(keypress_t *key)
{
    if (sfKeyboard_isKeyPressed(key->key) && !key->held) {
        key->pressed = 1;
        key->held = 1;
    }
    else
        key->pressed = 0;
    if (!sfKeyboard_isKeyPressed(key->key)) {
        key->pressed = 0;
        key->held = 0;
    }
}