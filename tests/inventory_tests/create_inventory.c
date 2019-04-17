/*
** EPITECH PROJECT, 2019
** create_inventory.c
** File description:
** all tests for create_inventory function
*/

#include <criterion/criterion.h>
#include "inventory.h"
#include <stdio.h>

/*
 * Test create_inventory(void);
 */

Test(create_inventory, create_an_inventory)
{
    inventory_t *inv = create_inventory();

    cr_assert_neq(inv, NULL);
    for (int i = 0; i < INV_SIZE; i++) {
        cr_assert_eq(inv->id[i], 0);
        cr_assert_eq(inv->amount[i], 0);
    }
    cr_assert_eq(inv->tmp_id, 0);
    cr_assert_eq(inv->tmp_amount, 0);
}
