/*
** EPITECH PROJECT, 2018
** my_setenv_one_arg
** File description:
** my_minishell
*/

#include "my.h"

char **my_setenv_one_arg(shell_t val_t, char **env)
{
	int check = 0;
	int pos = 0;
	int i = 0;
	char tab[2048];
	char **new_env = malloc(sizeof(char*) * 3);

	if ((pos = my_setenv_arg_check(val_t.args[1]) != 0))
		return (env);
	tab[0] = '\0';
	for (i = 0; env[i] != NULL; i++) {
		if (my_strcmp(env[i] , val_t.args[1]) == 1) {
			check = 1;
			pos = i;
		}
	}
	if (check == 1)
		return (env = my_check_yes_one_arg(env, pos, tab, val_t.args));
	else
		return (new_env = my_check_no_one_arg(new_env, env, val_t, i));
}

char **my_env_filling(char **new_env, char **env, char **args)
{
	int i = 0;

	for (i = 0; env[i] != NULL; i++) {
		new_env[i] = malloc(sizeof(char) * (len(env[i])));
		my_strcpy(new_env[i], env[i]);
	}
	new_env[i] = malloc(sizeof(char) * 1024);
	new_env[i] = my_strcat(args[1], "=");
	new_env[i + 1] = NULL;
	return (new_env);
}
