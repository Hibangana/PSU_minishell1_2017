/*
** EPITECH PROJECT, 2018
** my_parsers
** File description:
** my_minishell
*/

#include "my.h"

char *my_str_fill(char *args, char *str)
{
	int k = 0;
	static int i = 0;

	while (str[i] != '\0') {
		if (str[i] == ' ') {
			i++;
			args[k] = '\0';
			return (args);
		}
		args[k] = str[i];
		k++;
		i++;
	}
	i = 0;
	args[k] = '\0';
	return (args);
}

char **my_args_parser(shell_t val_t)
{
	int i = 0;
	int k = my_strlen(val_t.str);

	val_t.args = malloc(sizeof(char *) * (val_t.nb_a + 2));
	while (i <= (val_t.nb_a + 1)) {
		if (i == (val_t.nb_a + 1))
			val_t.args[i] = NULL;
		else {
			val_t.args[i] = malloc(sizeof(char)* (k + 1));
			val_t.args[i] = my_str_fill(val_t.args[i], val_t.str);
		}
		i++;
	}
	return (val_t.args);
}
