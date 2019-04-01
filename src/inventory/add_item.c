/*
** EPITECH PROJECT, 2019
** add_item.c
** File description:
** add an item to the inventory
*/

#include "inventory.h"

static int stack_item(int index, inventory_t *inv)
{
    int error = 0;

    if (inv->amount[index] < )  
    inv->amount[index]++;
    return (error);
}

int add_item(int id, inventory_t *inv)
{
    int error = 0;

    for (int i = 0; i < INV_SIZE; i++) {
        if (inv->id[i] == id) {
            error = stack_item(i, inv);
            return (error);
        }
    }
    return (inv);
}
