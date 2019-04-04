/*
** EPITECH PROJECT, 2019
** remplace_item.c
** File description:
** remplace an item by another in the temporary inventory case
*/

#include "inventory.h"

int remplace_item(int id, inventory_t *inv)
{
    int i = get_id(id, inv);

    if (i != -1) {
        inv->id[i] = inv->tmp_id;
        if (inv->tmp_amount <= MAX_STACK) {
            inv->amount[i] = inv->tmp_amount;
            inv->tmp_id = 0;
            inv->tmp_amount = 0;
            return (0);
        }
        else {
            inv->amount[i] = MAX_STACK;
            inv->tmp_amount = inv->tmp_amount - MAX_STACK;
            return (0);
        }
    }
    return (-1);
}
