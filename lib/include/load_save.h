/*
** EPITECH PROJECT, 2019
** load_save.h
** File description:
** header for load_save part
*/

#ifndef LOAD_SAVE
#define LOAD_SAVE

/* create_save.c */

int create_save(STRUCT_GAME);

/* write_save.c */

int write_save(int fd, STRUCT_GAME);

#endif /* !LOAD_SAVE */
