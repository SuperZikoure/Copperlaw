/*
** EPITECH PROJECT, 2019
** add_in_new_stack.c
** File description:
** add items in a new case if the last one is full
*/

#include "inventory.h"

int add_in_new_stack(int id, int index, inventory_t *inv)
{
    int error = 0;

    if (index != -1) {
        inv->id[index] = id;
        error = stack_item(index, inv);
        return (error);
    }
    return (-1);
}
