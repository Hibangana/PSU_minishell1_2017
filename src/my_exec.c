/*
** EPITECH PROJECT, 2018
** my_exec
** File description:
** my_minishell
*/

#include "my.h"

void my_exec(shell_t val_t, char **env)
{
	int cpid;
	int wstatus;
	int entry = 0;
	int waited;

	if (my_exit_check(val_t.args) == 1)
		return;
	cpid = fork();
	if (cpid == 0) {
		if (val_t.args[0][0] != '/') {
			my_exec_loop(val_t.paths, val_t.args, env, entry);
		}
		execve(val_t.args[0], val_t.args,env);
		if (wstatus != 139)
			my_command_not_found(val_t.args);
		exit(0);
	}
	if (cpid > 0) {
		waited = waitpid(-1, &wstatus, WUNTRACED | WCONTINUED);
		my_detect(waited, wstatus);
	}
}

void my_exec_loop(char **path, char **args, char **env, int entry)
{
	for (int i = 0; path[i] != NULL; i++) {
		my_strcat(path[i], args[0]);
		entry = access(path[i], X_OK);
		if (entry == 0)
			execve(path[i], args, env);
	}
	my_putstr(args[0]);
	my_putstr(": Command not found.\n");
	exit(0);
}

void my_command_not_found(char **args)
{
	my_putstr(args[0]);
	my_putstr(": Command not found.\n");
}
