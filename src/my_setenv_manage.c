/*
** EPITECH PROJECT, 2018
** my_setenv_manage
** File description:
** my_minishell
*/

#include "my.h"

char **my_setenv_manage(shell_t val_t, char **env)
{
	if (val_t.nb_a == 0)
		my_setenv_no_arg(env);
	if (val_t.nb_a == 1)
		env = my_setenv_one_arg(val_t, env);
	if (val_t.nb_a == 2)
		env = my_setenv_two_arg(val_t ,env);
	if (val_t.nb_a > 2)
		my_putstr("setenv: Too many arguments.\n");
	return (env);
}

void my_setenv_no_arg(char **env)
{
	for (int i = 0; env[i] != NULL; i++) {
		if (env[i][0] != '\0') {
			my_putstr(env[i]);
			my_putstr("\n");
		}
	}
}
