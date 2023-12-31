/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** add_item_with_index
*/

#include "inventory.h"

static int add_item_with_index_(int id, inventory_t *inv)
{
    int error = 0;
    int i = get_id(0, inv);

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

int add_item_with_index(int id, int i, inventory_t *inv)
{
    int error = 0;

    if (check_index(i) == -1)
        return (-1);
    if (inv->id[i] == id || inv->id[i] == 0) {
        if (inv->amount[i] < MAX_STACK) {
            inv->id[i] = id;
            error = stack_item(i, inv);
            return (error);
        }
    }
    error = add_item_with_index_(id, inv);
    return (error);
}

int add_stack_with_index(int id, int amount, int i, inventory_t *inv)
{
    int error = 0;

    for (int index = 0; index < amount; index++) {
        if (inv->id[i] == 0 || inv->id[i] == id)
            error = add_item_with_index(id, i, inv);
        else
            error = add_item(id, inv);
        if (error == -1)
            return (-1);
    }
    return (error);
}
