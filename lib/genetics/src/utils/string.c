/*
** EPITECH PROJECT, 2017
** string.c
** File description:
** Manipulate string header
*/

#include "genetics.h"

int my_strlen(const char *str)
{
	int count = 0;

	if (!(str))
		return (0);
	while (str[count] != '\0')
		count++;
	return (count);
}

char *my_strdup(const char *src)
{
	char *str;
	int len = my_strlen(src) + 1;

	if (!(len) || !(str = malloc(sizeof(char) * len)))
		return (NULL);
	str = my_strcpy(str, src);
	return (str);
}

char *my_strcpy(char *dest, const char *src)
{
	int i = 0;

	if (!(dest) || !(src))
		return (NULL);
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *my_strcat(char *dest, const char *src)
{
	int dest_len = my_strlen(dest);
	int j = 0;

	if (!(dest) || !(src))
		return (NULL);
	for (j = 0; src[j] != '\0'; j++)
		dest[dest_len + j] = src[j];
	dest[dest_len + j] = '\0';
	return (dest);
}

char *my_concat(char **str)
{
	int total_len = 0;
	char *result = NULL;

	if (!(str))
		return (NULL);
	for (int i = 0; str[i]; i++)
		total_len += my_strlen(str[i]);
	result = malloc(sizeof(char) * (total_len + 1));
	*result = '\0';
	for (int i = 0; str[i]; i++)
		my_strcat(result, str[i]);
	return (result);
}