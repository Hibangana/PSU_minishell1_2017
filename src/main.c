/*
** EPITECH PROJECT, 2018
** main
** File description:
** my_minishell
*/

#include "my.h"

int my_strlen(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++);
	return (i);
}

void my_putstr(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++)
		write(1, &str[i], 1);
}

void my_sigint(int sigint)
{
	sigint = 1;
	sigint = sigint;
	my_putstr("\n$>");
}

int main(int ac, char **av, char **envp)
{
	shell_t val_t;
	int end = 0;

	ac = ac;
	av = av;
	signal(SIGINT, my_sigint);
	while (!end) {
		if (isatty(0))
			my_putstr("$>");
		val_t.str = get_next_line(0);
		if (val_t.str != NULL)
			my_sh(val_t, envp);
		else {
			if (isatty(0))
				my_putstr("exit\n");
			end = !end;
		}
	}
	return (0);
}
