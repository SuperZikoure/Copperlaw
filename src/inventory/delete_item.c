/*
** EPITECH PROJECT, 2019
** delete_item.c
** File description:
** delete an item in the inventory
*/

#include "inventory.h"

int delete_item(int id, inventory_t *inv)
{
    int i = get_id(id, inv);

    if (i != -1 && inv->amount[i] != 0) {
        inv->amount[i]--;
        if (inv->amount[i] == 0)
            inv->id[i] = 0;
        return (0);
    }
    return (-1);
}

int delete_stack(int id, int amount, inventory_t *inv)
{
    int error = 0;

    for (int i = 0; i < amount; i++) {
        error = delete_item(id, inv);
        if (error == -1)
            return (-1);
    }
    return (0);
}
