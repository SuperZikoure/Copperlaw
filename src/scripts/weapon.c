/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** intro
*/

#include "scripts.h"

const struct script_s w_barman_script[] = {
    SAY("Burp.")
    END
};

const struct script_s w_blacksmith_script[] = {
    SAY("Watch me hitting this sword.")
    END
};

const struct script_s w_sheriff_script[] = {
    SAY("Looks like you got beat up by some monster.")
    SAY("If I were you, I wouldn't try bothering them.")
    SAY("But since you seek revenge, maybe you should find a weapon to fight")
    END
};

const struct script_s w_cowboy_script[] = {
    SAY("Act like you didn't see me.")
    END
};

const struct script_s w_note_script[] = {
    SAY("WANTED: Nut'o Ella")
    END
};

const struct script_s w_villager_script[] = {
    SAY("2")
    END
};

const struct script_s *weapon_scripts[] = {
    w_barman_script,
    w_blacksmith_script,
    w_sheriff_script,
    w_note_script,
    w_cowboy_script,
    w_villager_script,
    0
};
