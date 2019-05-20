/*
** EPITECH PROJECT, 2018
** my_unsetenv_manage
** File description:
** my_minishell
*/

#include "my.h"

void my_unsetenv_no_arg(void)
{
	my_putstr("unsetenv: Too few arguments.\n");
}

char **my_env_empty(char **env)
{
	env[0] = NULL;
	return (env);
}

char **my_unsetenv(shell_t val_t, char **env)
{
	int i = 0;
	int k = 1;

	if (val_t.args[1][0] == '*' && len(val_t.args[1]) == 1)
		return (env = my_env_empty(env));
	while (env[i] != NULL && val_t.args[k] != NULL) {
		if (my_strcmp(env[i], val_t.args[k]) == 1) {
			env[i][0] = '\0';
			k++;
		}
		i++;
	}
	return (env);
}

char **my_unsetenv_manage(shell_t val_t, char **env)
{
	if (val_t.nb_a == 0)
		my_unsetenv_no_arg();
	if (val_t.nb_a != 0)
		env = my_unsetenv(val_t, env);
	return (env);
}
