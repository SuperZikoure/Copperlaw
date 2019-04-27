/*
** EPITECH PROJECT, 2019
** check_index.c
** File description:
** check the index in params
*/

#include "inventory.h"

int check_index(int index)
{
    if (index >= 0 && index <= INV_SIZE)
        return (index);
    return (-1);
}
