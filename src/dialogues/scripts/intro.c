/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** intro
*/

#include "scripts.h"

NEW_SCRIPT(test_script_1) = {
    SAY("Whoa je veux une pomme.", PLAYER)
    SAY("eh beh bas moi j'en ai des bonnes", USR)
    SAY("oh oui ! je veux.", PLAYER)
    CHOSE2("c'est 2 gold la pomme tu la veux oui ou non ?", "oui", "non", USR)
    END
};

NEW_SCRIPT(test_script_2) = {
    SAY("le nutella c'est bon 0", NARRATOR)
    SAY("le nutella c'est bon 1", NARRATOR)
    SAY("le nutella c'est bon 2", NARRATOR)
    SAY("le nutella c'est bon 3", NARRATOR)
    SAY("le nutella c'est bon 4", NARRATOR)
    SAY("le nutella c'est bon 5", NARRATOR)
    SAY("le nutella c'est bon 6", NARRATOR)
    SAY("le nutella c'est bon 7", NARRATOR)
    SAY("le nutella c'est bon 8", NARRATOR)
    SAY("le nutella c'est bon 9", NARRATOR)
    SAY("le nutella c'est bon 10", NARRATOR)
    SAY("le nutella c'est bon 11", NARRATOR)
    SAY("le nutella c'est bon 12", NARRATOR)
    SAY("le nutella c'est bon 13", NARRATOR)
    SAY("le nutella c'est bon 14", NARRATOR)
    CHOSE3("le nutella c'est quoi a ton avis ???????", "bon", "Bon", "Super mega bon tu peux pas test mon gars",
NARRATOR)
    END
};
