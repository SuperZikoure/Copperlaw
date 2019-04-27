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
        return (stack_item(i, inv));
    }
    i = get_id(0, inv);
    if (i != -1)
        return (add_in_new_stack(id, i, inv));
    else {
        inv->tmp_id = id;
        inv->tmp_amount++;
        return (-1);
    }
    return (-1);
}

int add_stack(int id, int amount, inventory_t *inv)
{
    for (int i = 0; i < amount; i++) {
        if (add_item(id, inv) == -1)
            return (-1);
    }
    return (0);
}
