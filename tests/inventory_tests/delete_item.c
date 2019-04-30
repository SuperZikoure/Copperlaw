/*
** EPITECH PROJECT, 2019
** delete_item.c
** File description:
** all tests for delete_item function
*/

#include <criterion/criterion.h>
#include "inventory.h"
#include <stdio.h>

/*
* Test delete_item(int id, inventory_t *inv)
* #define INV_SIZE = 100 &&
* #define MAX_STACK = 64 to build tests
*/

Test(delete_item, in_an_inventory_fulled_with_same_id)
{
    inventory_t *inv = create_inventory();
    int item_id = 1600;
    int error;

    flood_inventory(1600, inv);
    error = delete_item(item_id, inv);
    cr_assert_eq(error, 0);
    cr_assert_eq(inv->id[0], 1600);
    cr_assert_eq(inv->amount[0], 63);
}

Test(delete_item, in_an_inventory_fulled_with_diffrents_id)
{
    inventory_t *inv = create_inventory();
    int item_id = 1600;
    int error;

    inv->id[0] = 1597;
    inv->amount[0] = 12;
    inv->id[1] = 1598;
    inv->amount[1] = 2;
    inv->id[2] = 1600;
    inv->amount[2] = 1;
    error = delete_item(item_id, inv);
    cr_assert_eq(error, 0);
    cr_assert_eq(inv->id[2], 0);
    cr_assert_eq(inv->amount[2], 0);
}

Test(delete_item, item_not_found)
{
    inventory_t *inv = create_inventory();
    int item_id = 1600;
    int error;

    flood_inventory(1, inv);
    error = delete_item(item_id, inv);
    cr_assert_eq(error, -1);
}
