/*
** EPITECH PROJECT, 2018
** Genetics library
** File description:
** Manipulate string
*/

#include "genetics.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;

	for (i = 0; s1[i] == s2[i] && s1[i] && i < n; i++);
	if (i < n)
		return (s1[i] - s2[i]);
	return (0);
}

char *my_itc(int nbr)
{
	int len = number_digits(nbr);
	char *result;

	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	while (len--) {
		result[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (result);
}

int number_digits(int nbr)
{
	int n = 1;
	int po = 10;

	if (nbr < 0)
		nbr = -nbr;
	while (nbr >= po) {
		n++;
		if (po > 214748364)
			break;
		po *= 10;
	}
	return (n);
}