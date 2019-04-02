/*
** EPITECH PROJECT, 2019
** file.h
** File description:
** header of my_file lib
*/

#ifndef FILE
#define FILE

#include "my.h"
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

typedef struct fileinf_s {
    int fd;
    char *cont;
    struct stat *st;
} fileinf_t;

typedef struct dirinf_s {
    DIR *flux;
    struct dirent *dirent;
} dirinf_t;

/* files functions */

int open_file(char *filepath);
char *read_file(char *filepath);
struct stat *init_stat(char *filepath);
int close_file(fileinf_t *dir);
fileint_t *init_fileinf(char *filepath);
void free_fileinf(fileinf_t *dir);
int write_file(int fd, char *cont);
int create_file(char *filename);

/* directories functions */

DIR *open_dir(char *filepath);
struct dirent *read_dir(char *filepath);
int close_dir(dirinf_t *dir);
dirint_t *init_dirinf(char *filepath);
void free_dirinf(dirinf_t *dir);

/* both functions*/

int is_dir(char *filepath);
int check_access(char *filepath);

#endif
