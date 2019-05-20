/*
** EPITECH PROJECT, 2018
** my_h
** File description:
** my_minishell
*/

#ifndef MY_H_
#define MY_H_
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define len my_strlen
struct my_minishell
{
	char **args;
	char **paths;
	char **env;
	char *str;
	char *path_s;
	int nb_p;
	int nb_a;
	int cd_count;
	int stat;
};
typedef struct my_minishell shell_t;
shell_t my_cd_normal_stat_check(shell_t, char*);
shell_t my_cd_slash_stat_check(shell_t, int);
char **my_path_filler(shell_t);
char **my_args_parser(shell_t);
char **my_setenv_two_arg(shell_t, char **);
char **my_setenv_one_arg(shell_t, char **);
char **my_check_yes_one_arg(char **, int, char *, char **);
char **my_check_yes_two_arg(char **, int, char *, char **);
char **my_check_no_one_arg(char **, char **, shell_t, int);
char **my_check_no_two_arg(char **, char **, shell_t, int);
char **my_env_filling(char **, char **, char **);
char **my_env_filling_two(char **, char **, char **);
char **my_setenv_manage(shell_t, char**);
char **my_unsetenv_manage(shell_t, char**);
char **my_cd_manage(shell_t, char**);
char **my_sh_loop(shell_t, char **);
char *my_str_fill(char *, char*);
char *my_path_string_fill(char*, char*);
char *my_pathfinder(char**);
char *get_next_line(int);
char *my_strcpy(char *, char*);
char *my_strcat(char *, char*);
char *my_str_clean(char *);
int my_exit_check(char **);
int my_cd_dash_normer(shell_t);
int my_setenv_arg_check(char *);
int my_numb_of_path(char *);
int my_numb_of_arg(char *);
int my_begin_is_space(char *);
int my_strcmp(char*, char*);
int my_exit_check(char **);
int my_env_error(char **);
int my_strlen(char*);
void my_exec_dot(shell_t, char **);
void my_detect(int, int);
void my_exec_loop(char **, char **, char **, int);
void my_command_not_found(char **);
void my_exec(shell_t, char **);
void my_setenv_no_arg(char **);
void my_env_manage(shell_t, char **);
void my_null_env_or_string(char *);
void my_sh(shell_t, char**);
void my_putstr(char*);
#endif
