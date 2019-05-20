/*
** EPITECH PROJECT, 2018
** my_numb_of
** File description:
** my_minishell
*/

#include "my.h"

int my_numb_of_path(char *path_single)
{
	int i = 0;
	int count = 0;

	while (path_single[i] != '\0') {
		if (path_single[i] == ':')
			count++;
		i++;
	}
	count = count + 2;
	return (count);
}

int my_numb_of_arg(char *av)
{
	int i = 0;
	int count = 0;

	while (av[i] != '\0') {
		if ((av[i] == ' ' && av[i + 1] != '\0' && av[i + 1] != ' '))
			count++;
		i++;
	}
	return (count);
}
