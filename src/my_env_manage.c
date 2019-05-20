/*
** EPITECH PROJECT, 2018
** my_env_manage
** File description:
** my_minishell
*/

#include "my.h"

void my_env_manage(shell_t val_t, char **env)
{
	if (val_t.nb_a != 0) {
		my_putstr("env: '");
		my_putstr(val_t.args[1]);
		my_putstr("': No such file or directory\n");
		return;
	}
	for (int i = 0; env[i] != NULL; i++) {
		if (env[i][0] != '\0') {
			my_putstr(env[i]);
			my_putstr("\n");
		}
	}
}
