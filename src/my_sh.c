/*
** EPITECH PROJECT, 2018
** my_sh
** File description:
** my_minishell
*/

#include "my.h"

shell_t my_struct_params(char **env, shell_t val_t)
{
	val_t.path_s = my_pathfinder(env);
	val_t.nb_p = my_numb_of_path(val_t.path_s);
	val_t.paths = my_path_filler(val_t);
	val_t.str = my_str_clean(val_t.str);
	val_t.nb_a = my_numb_of_arg(val_t.str);
	val_t.args = my_args_parser(val_t);
	val_t.stat = 0;
	return (val_t);
}

void my_sh(shell_t val_t, char **envp)
{
	static int loop = 0;
	static char **env;

	if (loop == 0) {
		env = envp;
		loop = 1;
		val_t.cd_count = 0;
	}
	if (len(val_t.str)==0||val_t.str == NULL || my_env_error(env) == 1) {
		my_null_env_or_string(val_t.str);
		return;
	}
	val_t = my_struct_params(env, val_t);
	env = my_sh_loop(val_t, env);
}

char **my_sh_loop(shell_t val_t, char **env)
{
	if (my_strcmp(val_t.str, "env") == 1 && len(val_t.args[0]) == 3) {
		my_env_manage(val_t, env);
		return (env);
	}
	if (my_strcmp(val_t.str, "setenv") == 1 && len(val_t.args[0]) == 6) {
		env = my_setenv_manage(val_t, env);
		return (env);
	}
	if (my_strcmp(val_t.str, "unsetenv") == 1 && len(val_t.args[0]) == 8) {
		env = my_unsetenv_manage(val_t, env);
		return (env);
	}
	if (my_strcmp(val_t.str, "cd") == 1 && len(val_t.args[0]) == 2) {
		env = my_cd_manage(val_t, env);
		return (env);
	}
	if (val_t.args[0][0] == '.')
		my_exec_dot(val_t, env);
	else
		my_exec(val_t, env);
	return (env);
}
