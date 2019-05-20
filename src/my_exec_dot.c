/*
** EPITECH PROJECT, 2018
** my_exec_dot
** File description:
** my_minishell
*/

#include "my.h"

char *my_foward(char *str)
{
	char *av = malloc(sizeof(char) * (my_strlen(str) + 1));
	int i = 1;
	int k = 0;

	while (str[i] != '\0') {
		av[k] = str[i];
		i++;
		k++;
	}
	av[k] = '\0';
	free(str);
	return (av);
}

void my_bad_output(char **args, int i)
{
	if (args[0][i - 1] != '/')
		my_putstr(": Command not found.\n");
	else
		my_putstr(": Not a directory.\n");
}

void my_put_one(char **args)
{
	my_putstr(".");
	my_putstr(args[0]);
}

void my_exec_dot(shell_t val_t, char **env)
{
	char cwd[1024];
	int cpid;
	int wstatus;
	int i = 0;
	int waited;

	getcwd(cwd, sizeof(cwd));
	val_t.args[0] = my_foward(val_t.args[0]);
	my_strcat(cwd, val_t.args[0]);
	cpid = fork();
	if (cpid == 0) {
		execve(cwd, val_t.args, env);
		my_put_one(val_t.args);
		for (i = 0; val_t.args[0][i]; i++);
		my_bad_output(val_t.args, i);
		exit(wstatus);
	}
	if (cpid > 0) {
		waited = waitpid(-1, &wstatus, WUNTRACED | WCONTINUED);
		my_detect(waited, wstatus);
	}
}
