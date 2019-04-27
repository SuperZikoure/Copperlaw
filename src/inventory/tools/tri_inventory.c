/*
** EPITECH PROJECT, 2019
** tri_inventory.c
** File description:
** tri the inventory placing voids at the end
*/

static void retri_all(inventory_t *inv, int i)
{
    while (inv->id[i] != 0) {
        inv->id[i - 1] = inv->id[i];
        inv->amount[i - 1] = inv->amount[i];
        i++;
    }
    inv->id[i] = 0;
    inv->amount[i] = 0;
}

void tri_inventory(inventory_t *inv)
{
    for (int i = 0; i < INV_SIZE; i++) {
        if (inv->id[i] == 0)
            retri_all(inv, i++, call);
    }
}
