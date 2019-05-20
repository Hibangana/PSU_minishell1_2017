/*
** EPITECH PROJECT, 2018
** my_detect
** File description:
** my_minishell
*/

#include "my.h"

void my_detect(int waited, int wstatus)
{
	int detect = 0;
	char *str = strsignal(WTERMSIG(wstatus));

	if (waited == -1)
		exit(EXIT_FAILURE);
	if (my_strcmp(str, "Segmentation fault") == 1) {
		write(2, "Segmentation fault", 18);
		detect = 1;
	}
	if (my_strcmp(str, "Floating point exception") == 1) {
		write(2, "Floating exception", 18);
		detect = 1;
	}
	if (my_strcmp(str, "Aborted") == 1) {
		write(2, "Abort", 5);
		detect = 1;
	}
	if (detect == 1)
		write(2, "\n", 1);
}
