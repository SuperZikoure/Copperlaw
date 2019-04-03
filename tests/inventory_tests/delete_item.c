/*
** EPITECH PROJECT, 2019
** delete_item.c
** File description:
** all tests for delete_item and delete_stack functions
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

/*
 * Test delete_stack(int id, int amount, inventory_t *inv)
 */

Test(delete_stack, in_an_inventory_fulled_with_same_id)
{
    inventory_t *inv = create_inventory();
    int item_id = 1600;
    int amount = 32;
    int error;

    flood_inventory(1600, inv);
    error = delete_stack(item_id, amount, inv);
    cr_assert_eq(error, 0);
    cr_assert_eq(inv->id[0], 1600);
    cr_assert_eq(inv->amount[0], 32);
}

Test(delete_stack, delete_a_stack_bigger_than_max_stack)
{
    inventory_t *inv = create_inventory();
    int item_id = 1600;
    int amount = 65;
    int error;

    flood_inventory(1600, inv);
    error = delete_stack(item_id, amount, inv);
    cr_assert_eq(error, 0);
    cr_assert_eq(inv->id[0], 0);
    cr_assert_eq(inv->amount[0], 0);
    cr_assert_eq(inv->id[1], 1600);
    cr_assert_eq(inv->amount[1], 63);
}

Test(delete_stack, item_not_found)
{
    inventory_t *inv = create_inventory();
    int item_id = 1600;
    int amount = 2;
    int error;

    flood_inventory(1, inv);
    error = delete_stack(item_id, amount, inv);
    cr_assert_eq(error, -1);
}
