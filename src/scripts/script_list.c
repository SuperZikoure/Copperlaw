/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** script_list
*/

#include "scripts.h"

const struct script_s **script_list[ZONE_NB] = {
    intro_scripts,
    weapon_scripts,
    village_scripts
};
