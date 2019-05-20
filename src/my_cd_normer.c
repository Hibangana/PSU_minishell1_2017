/*
** EPITECH PROJECT, 2018
** my_cd_normer
** File description:
** my_minishell
*/

#include "my.h"

int my_cd_dash_normer(shell_t val_t)
{
	if (len(val_t.args[1]) != 1) {
		my_putstr("Usage: cd [-plvn][-|<dir>].\n");
		return (1);
	}
	if (val_t.cd_count == 0 && len(val_t.args[1]) == 1) {
		my_putstr(": No such file or directory.\n");
		return (1);
	}
	return (0);
}

shell_t my_cd_normal_stat_check(shell_t val_t, char *cwd)
{
	val_t.stat = chdir(cwd);
	if (val_t.stat == -1) {
		my_putstr(val_t.args[1]);
		my_putstr(": No such file or directory.\n");
	}
	val_t.cd_count = 1;
	return (val_t);
}

void my_cd_error_checking(shell_t val_t)
{
	struct stat stock;
	stat((val_t.args[1]), &stock);
	switch (stock.st_mode & S_IFMT) {
	case S_IFREG:
		my_putstr(val_t.args[1]);
		my_putstr(": Not a directory.\n");
		break;
	default:
		my_putstr(val_t.args[1]);
		my_putstr(": No such file or directory.\n");
		break;
	}
}

shell_t my_cd_slash_stat_check(shell_t val_t, int stat)
{
	if (stat == -1)
		my_cd_error_checking(val_t);
	val_t.cd_count = 1;
	return (val_t);
}
