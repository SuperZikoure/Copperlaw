/*
** EPITECH PROJECT, 2019
** delete_item_with_index.c
** File description:
** delete an item with his index in the inventory
*/

#include "inventory.h"

int delete_item_with_index(int index, inventory_t *inv)
{
    int i = check_index(index);

    if (i != -1 && inv->amount[i] > 0) {
        inv->amount[i]--;
        if (inv->amount[i] == 0)
            inv->id[i] = 0;
        return (0);
    }
    return (-1);
}

int delete_stack_with_index(int index, int amount, inventory_t *inv)
{
    int error = 0;

    if (amount > MAX_STACK)
        return (-1);
    for (int i = 0; i < amount; i++) {
        error = delete_item_with_index(index, inv);
        if (error == -1)
            return (-1);
    }
    return (0);
}
