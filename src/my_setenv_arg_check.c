/*
** EPITECH PROJECT, 2018
** my_setenv_arg_check
** File description:
** my_minishell
*/

#include "my.h"

void my_put_setenv_error(void)
{
	my_putstr("setenv: Variable name must contain");
	my_putstr(" alphanumeric characters.\n");
}

int my_setenv_arg_check(char *str)
{
	int i = 0;

	if((str[i] >= 'A' && str[i] <= 'Z') ||
	(str[i] >= 'a' && str[i] <= 'z'))
		i = 1;
	else {
		my_put_setenv_error();
		return (1);
	}
	while(str[i] != '\0') {
		if((str[i] >= 'A' && str[i] <= 'Z') ||
		(str[i] >= 'a' && str[i] <= 'z') ||
		(str[i] >= '0' && str[i] <= '9'))
			i++;
		else {
			my_put_setenv_error();
			return (1);
		}
	}
	return (0);
}
