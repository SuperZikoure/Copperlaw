/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** fetch_oldest_dialogue_response.c
*/

#include "my_rpg.h"

static int store_variable(int choice)
{
    static int storage = -1;

    if (choice == -2)
        return storage;
    storage = choice;
    return storage;
}

void store_response(int choice)
{
    store_variable(choice);
}

int get_response(void)
{
    return (store_variable(-2));
}
