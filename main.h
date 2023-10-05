#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <time.h>
#include <ctype.h>

extern char **environ;

int is_numeric(const char *str);
int stringcmp(char *str1, char *str2);
int path(char **arguments);
char *stringdup(char *str);
char *add_command(char *dir_path, char *command);
int exec(char **arguments);
int user_args(char *entry, char **arguments);
int print_numbers(int n);
size_t stringlen(const char *string);
int not_found(char **arguments, int counter);
char *get_env(char *global_var);
int prompt(const char *prompt, unsigned int size);
int _putchar(char c);
int isthere(char *pathname);
void dealloc(char **grid, int heigth);
void last_dealloc(char *entry);
int blt(char **arguments, int exit_stat);

#endif
