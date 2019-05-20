/*
** EPITECH PROJECT, 2018
** my_check
** File description:
** my_minishell
*/

#include "my.h"

int my_env_error(char **envp)
{
	int k = 0;

	if (envp[0] == NULL)
		return (1);
	for (int i = 0; envp[i] != NULL; i++)
		k = k + my_strcmp(envp[i], "PATH");
	if (k != 0)
		return (0);
	return (1);
}

void my_null_env_or_string(char *str)
{
	if (my_strlen(str) != 0 && str != NULL) {
		str = my_str_clean(str);
		my_putstr(str);
		my_putstr(": Command not found.\n");
	}
}
