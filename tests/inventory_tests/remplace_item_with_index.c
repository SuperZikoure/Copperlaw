/*
** EPITECH PROJECT, 2019
** remplace_item_with_index.c
** File description:
** all tests for remplace_item_with_index function
*/

#include <criterion/criterion.h>
#include "inventory.h"
#include <stdio.h>

/*
 * Test remplace_item_with_index(int id, int i, inventory_t *inv)
 * #define INV_SIZE = 100 &&
 * #define MAX_STACK = 64 to build tests
 */

Test(remplace_item_with_index, in_an_inventory_full)
{
    inventory_t *inv = create_inventory();
    int error;
    int index = 10;

    flood_inventory(1, inv);
    inv->tmp_id = 1600;
    inv->tmp_amount = 5;
    error = remplace_item_with_index(index, inv);
    cr_assert_eq(error, 0);
    cr_assert_eq(inv->id[10], 1600);
    cr_assert_eq(inv->amount[10], 5);
    cr_assert_eq(inv->tmp_id, 0);
    cr_assert_eq(inv->tmp_amount, 0);
}

Test(remplace_item_with_index, amount_superior_to_max_stack)
{
    inventory_t *inv = create_inventory();
    int error;
    int index = 1;

    flood_inventory(1, inv);
    inv->tmp_id = 1600;
    inv->tmp_amount = 130;
    error = remplace_item_with_index(index, inv);
    cr_assert_eq(error, 0);
    cr_assert_eq(inv->id[1], 1600);
    cr_assert_eq(inv->amount[1], MAX_STACK);
    cr_assert_eq(inv->tmp_id, 1600);
    cr_assert_eq(inv->tmp_amount, 66);
}
