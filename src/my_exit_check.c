/*
** EPITECH PROJECT, 2018
** my_exit_check
** File description:
** my_minishell
*/

#include "my.h"

int my_arg_is_numb(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void my_exit_output(void)
{
	if (isatty(0))
		my_putstr("exit\n");
	exit(0);
}

int my_exit_check(char **str)
{
	int i = 0;

	for (i = 0; str[i] != NULL; i++);
	if (my_strcmp(str[0], "exit") == 1 && my_strlen(str[0])==4 && i == 1)
		my_exit_output();
	if (i == 1 && my_strcmp(str[0], "exit") == 1 && my_strlen(str[0])== 4){
		my_putstr("exit: Expression Syntax.\n");
		return (1);
	}
	if (i == 2 && my_strcmp(str[0], "exit") == 1 && my_strlen(str[0])== 4){
		if (my_arg_is_numb(str[1]) == 1) {
			if (isatty(0))
				my_putstr("exit\n");
			exit(0);
		}
		my_putstr("exit: Expression Syntax.\n");
		return (1);
	}
	return (0);
}
