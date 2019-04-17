/*
** EPITECH PROJECT, 2019
** remplace_item.c
** File description:
** all tests for remplace_item function
*/

#include <criterion/criterion.h>
#include "inventory.h"
#include <stdio.h>

/*
 * Test remplace_item(int id, inventory_t *inv)
 * #define INV_SIZE = 100 &&
 * #define MAX_STACK = 64 to build tests
 */

Test(remplace_item, in_an_inventory_full)
{
    inventory_t *inv = create_inventory();
    int error;
    int item_id = 1;

    flood_inventory(1, inv);
    inv->tmp_id = 1600;
    inv->tmp_amount = 5;
    error = remplace_item(item_id, inv);
    cr_assert_eq(error, 0);
    cr_assert_eq(inv->id[0], 1600);
    cr_assert_eq(inv->amount[0], 5);
    cr_assert_eq(inv->tmp_id, 0);
    cr_assert_eq(inv->tmp_amount, 0);
}

Test(remplace_item, item_not_found)
{
    inventory_t *inv = create_inventory();
    int error;

    flood_inventory(1, inv);
    inv->tmp_id = 1600;
    inv->tmp_amount = 5;
    error = remplace_item(666, inv);
    cr_assert_eq(error, -1);
    cr_assert_eq(inv->tmp_id, 1600);
    cr_assert_eq(inv->tmp_amount, 5);
}

Test(remplace_item, amount_superior_to_max_stack)
{
    inventory_t *inv = create_inventory();
    int error;
    int item_id = 1;

    flood_inventory(1, inv);
    inv->tmp_id = 1600;
    inv->tmp_amount = 130;
    error = remplace_item(item_id, inv);
    cr_assert_eq(error, 0);
    cr_assert_eq(inv->id[0], 1600);
    cr_assert_eq(inv->amount[0], MAX_STACK);
    cr_assert_eq(inv->tmp_id, 1600);
    cr_assert_eq(inv->tmp_amount, 66);
}
