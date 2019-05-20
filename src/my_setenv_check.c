/*
** EPITECH PROJECT, 2018
** my_setenv_check
** File description:
** my_minishell
*/

#include "my.h"

char **my_check_yes_one_arg(char **env, int pos, char *tab, char **args)
{
	env[pos] = my_strcat(tab, args[1]);
	env[pos] = my_strcat(tab, "=");
	return (env);
}

char **my_check_no_one_arg(char **new_env, char **envp, shell_t val_t, int i)
{
	new_env = malloc(sizeof(char *) * ( i + 2 ));
	new_env = my_env_filling(new_env, envp, val_t.args);
	return (new_env);
}

char **my_check_yes_two_arg(char **env, int pos, char *tab, char **args)
{
	env[pos] = my_strcat(tab, args[1]);
	env[pos] = my_strcat(tab, "=");
	env[pos] = my_strcat(tab, args[2]);
	return (env);
}

char **my_check_no_two_arg(char **env, char **envp, shell_t val_t, int i)
{
	env = malloc(sizeof(char*) *(i + 2));
	env = my_env_filling_two(env, envp, val_t.args);
	return (env);
}
