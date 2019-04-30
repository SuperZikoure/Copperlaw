/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** village
*/

#include "scripts.h"

NEW_SCRIPT(blank_village)
{
    SAY("...", NARRATOR)
    END
};

NEW_SCRIPT(test_village_1)
{
    CHOSE2("c'est 2 gold la pomme tu la veux oui ou non ?", "oui", "non", USR)
    END
};

NEW_SCRIPT(test_village_2)
{
    SAY("le nutella c'est bon 14", NARRATOR)
    CHOSE3("le nutella c'est quoi a ton avis ???????", "bon", "Bon",
"Super mega bon tu peux pas test mon gars", NARRATOR)
    END
};

const struct script_s *village_scripts[] = {
    blank_village,
    test_village_1,
    test_village_2,
    0
};
