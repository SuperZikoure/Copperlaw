/*
** EPITECH PROJECT, 2019
** add_item.c
** File description:
** all tests for add_item function
*/

#include <criterion/criterion.h>
#include "inventory.h"
#include <stdio.h>

/*
 * Test add_item(int id, inventory_t *inv)
 * #define INV_SIZE = 100 &&
 * #define MAX_STACK = 64 to build tests
 */

Test(add_item, add_an_item_in_an_empty_inventory)
{
    inventory_t *inv = create_inventory();
    int item_id = 1600;
    int error = add_item(item_id, inv);

    cr_assert_eq(error, 0);
    cr_assert_eq(inv->id[0], 1600);
    cr_assert_eq(inv->amount[0], 1);
}

Test(add_item, add_an_item_in_an_inventory_semi_full)
{
    inventory_t *inv = create_inventory();
    int item_id = 1600;
    int error;

    inv->id[0] = 1597;
    inv->amount[0] = 12;
    inv->id[1] = 1598;
    inv->amount[1] = 2;
    inv->id[2] = 1599;
    inv->amount[2] = 24;
    error = add_item(item_id, inv);
    cr_assert_eq(error, 0);
    cr_assert_eq(inv->id[3], 1600);
    cr_assert_eq(inv->amount[3], 1);
}

Test(add_item, add_an_item_in_a_stack)
{
    inventory_t *inv = create_inventory();
    int item_id = 1600;
    int error;

    inv->id[0] = 1600;
    inv->amount[0] = 9;
    error = add_item(item_id, inv);
    cr_assert_eq(error, 0);
    cr_assert_eq(inv->id[0], 1600);
    cr_assert_eq(inv->amount[0], 10);
}

Test(add_item, add_an_item_in_a_full_inventory)
{
    inventory_t *inv = create_inventory();
    int item_id = 1600;
    int error;

    for(int i = 0; i < INV_SIZE; i++) {
        inv->id[i] = 1;
        inv->amount[i] = MAX_STACK;
    }
    error = add_item(item_id, inv);
    cr_assert_eq(error, -1);
    cr_assert_eq(inv->tmp_id, 1600);
    cr_assert_eq(inv->tmp_amount, 1);
}
