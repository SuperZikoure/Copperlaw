/*
** EPITECH PROJECT, 2019
** add_item.c
** File description:
** add an item to the inventory
*/

#include "inventory.h"

int add_item(int id, inventory_t *inv)
{
    int error = 0;
    int i = get_id_free(id, inv);

    if (i != -1 && inv->amount[i] < MAX_STACK) {
        inv->id[i] = id;
        error = stack_item(i, inv);
        return (error);
    }
    i = get_id(0, inv);
    if (i != -1) {
        error = add_in_new_stack(id, i, inv);
        return (error);
    }
    else {
        inv->tmp_id = id;
        inv->tmp_amount++;
        return (-1);
    }
    return (-1);
}

int add_stack(int id, int amount, inventory_t *inv)
{
    int error = 0;

    for (int i = 0; i < amount; i++) {
        error = add_item(id, inv);
        if (error == -1)
            return (-1);
    }
    return (error);
}
