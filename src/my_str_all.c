/*
** EPITECH PROJECT, 2018
** my_strall
** File description:
** my_minishell
*/

#include "my.h"

char *my_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *my_strcat(char *dest, char *src)
{
	int i = 0;
	int k = 0;

	while (dest[i] != '\0')
		i++;
	while (src[k] != '\0') {
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (dest);
}

int my_strcmp(char *str, char *strme)
{
	int i = 0;

	while (strme[i] != '\0') {
		if (str[i] != strme[i])
			return (0);
		i++;
	}
	return (1);
}
