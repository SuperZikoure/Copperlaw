/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** my_float_to_str
*/

#include <math.h>
#include <stdlib.h>
#include "my.h"
#include "my_string.h"

static int split_float(float nb, int *integral)
{
    float tmp_integral;
    float decimal = modff(nb, &tmp_integral);

    *integral = tmp_integral;
    return decimal * 100;
}

char *my_float_to_str(float nb)
{
    int integral;
    int decimal = split_float(nb, &integral);
    char *str = my_itoa(integral);

    if (!str)
        return NULL;
    if (decimal) {
        str = my_strcat(str, my_strdup("."));
        str = my_strcat(str, my_itoa(decimal));
    }
    return str;
}
