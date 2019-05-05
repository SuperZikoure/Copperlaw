/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** intro
*/

#include "scripts.h"

const struct script_s i_barman_script[] = {
    SAY("Burp.")
    END
};

const struct script_s i_blacksmith_script[] = {
    SAY("Hey stranger, want a weap...")
    SAY("Wait you don't have any money...")
    SAY("Sorry, no money, no weapon.")
    END
};

const struct script_s i_sheriff_script[] = {
    SAY("Looks like you got beat up by some monster.")
    SAY("If I were you, I wouldn't try bothering them.")
    SAY("But since you seek revenge, maybe you should find a weapon to fight")
    SAY("Here is some money to excuse my inattention.")
    SAY("Maybe you can get one. But that you need you to ask the blacksmith.")
    END
};

const struct script_s i_cowboy_script[] = {
    SAY("Do as if you did not see me.")
    END
};

const struct script_s i_note_script[] = {
    SAY("WANTED: Nut'o Ella")
    END
};

const struct script_s i_villager_script[] = {
    SAY("Hey you finally awake!")
    SAY("You were trying to cross the lake, right?")
    SAY("I found you on the verge of dying, hopefully you will recover in \
a few!")
    SAY("If you can move, try talking to the sheriff, he can tell you more \
about your situation.")
    END
};

const struct script_s *intro_scripts[] = {
    i_barman_script,
    i_blacksmith_script,
    i_sheriff_script,
    i_note_script,
    i_cowboy_script,
    i_villager_script,
    0
};
