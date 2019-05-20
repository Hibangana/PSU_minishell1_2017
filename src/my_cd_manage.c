/*
** EPITECH PROJECT, 2018
** my_cd_manage
** File description:
** my_minishell
*/

#include "my.h"

char *my_home_finder(char** env, char *my_home)
{
	char *str;
	int i = 0;
	int k = 5;
	int c = 0;

	free(my_home);
	for (i = 0; my_strcmp(env[i], "HOME") != 1; i++);
	str = malloc(sizeof(char) * (len(env[i]) + 1));
	for (; env[i][k] != '\0'; k++) {
		str[c] = env[i][k];
		c++;
	}
	str[c] = '\0';
	return (str);
}

void my_root(char **env)
{
	char *my_home = malloc(sizeof(char) * 3);

	my_home = my_home_finder(env,my_home);
	chdir(my_home);
}

void micro_normer(char *memory, char*cwd, shell_t val_t)
{
	my_strcpy(memory, cwd);
	my_strcat(cwd, "/");
	my_strcat(cwd, val_t.args[1]);
}

void my_cd(shell_t val_t)
{
	char cwd[1024];
	static char memory[1024];

	if (val_t.args[1][0] == '-') {
		if (my_cd_dash_normer(val_t) == 0) {
			getcwd(cwd, sizeof(cwd));
			chdir(memory);
			my_strcpy(memory, cwd);
		}
	}
	if (val_t.args[1][0] != '/' && val_t.args[1][0] != '-') {
		getcwd(cwd, sizeof(cwd));
		micro_normer(memory, cwd, val_t);
		val_t = my_cd_normal_stat_check(val_t, cwd);
	}
	if (val_t.args[1][0] == '/') {
		getcwd(cwd, sizeof(cwd));
		val_t.stat = chdir(val_t.args[1]);
		my_strcpy(memory, cwd);
		val_t = my_cd_slash_stat_check(val_t, val_t.stat);
	}
}

char **my_cd_manage(shell_t val_t, char **env)
{
	if (val_t.nb_a == 0)
		my_root(env);
	if (val_t.nb_a > 1)
		my_putstr("cd: Too many arguments.\n");
	if (val_t.nb_a == 1)
		my_cd(val_t);
	return (env);
}
