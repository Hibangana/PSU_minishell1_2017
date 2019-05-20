/*
** EPITECH PROJECT, 2018
** my_paths
** File description:
** my_minishell
*/

#include "my.h"

char *my_pathfinder(char **envp)
{
	char *str;
	int i = 0;
	int k = 0;
	int q = 5;

	for (i = 0; my_strcmp(envp[i], "PATH") != 1; i++);
	str = malloc(sizeof(char) * (my_strlen(envp[i]) + 1) );
	while (envp[i][q] != '\0') {
		str[k] = envp[i][q];
		k++;
		q++;
	}
	str[k] = '\0';
	return (str);
}

char **my_path_filler(shell_t val_t)
{
	char **str = malloc(sizeof(char *) * (val_t.nb_p));

	for (int i = 0; i <= (val_t.nb_p - 1); i++) {
		str[i] = malloc(sizeof(char) * (len(val_t.path_s) + 1));
		if (i == val_t.nb_p - 1)
			str[i] = NULL;
		else
			str[i] = my_path_string_fill(str[i], val_t.path_s);
	}
	return (str);
}

char *my_path_string_fill(char *path, char *str)
{
	int k = 0;
	static int i = 0;

	while (str[i] != '\0') {
		if (str[i] == ':' || str[i] == '\0') {
			i++;
			path[k] = '/';
			path[k + 1] = '\0';
			return (path);
		}
		path[k] = str[i];
		k++;
		i++;
	}
	i = 0;
	path[k] = '/';
	path[k + 1] = '\0';
	return (path);
}
