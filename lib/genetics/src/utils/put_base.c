/*
** EPITECH PROJECT, 2017
** Genetics library
** File description:
** Put number base header
*/

#include "genetics.h"

int my_putnbr_base(int nbr, const char *base)
{
	int result = 0;
	int power = 1;
	int len_base = my_strlen(base);

	if (nbr == -1) {
		my_put_str("FFFFFFFF");
		return (0);
	}
	if (nbr < 0) {
		my_put_char('-');
		nbr = -nbr;
	}
	while ((nbr / power) >= len_base)
		power *= len_base;
	while (power > 0) {
		result = (nbr / power) % len_base;
		my_put_char(base[result]);
		power = power / len_base;
	}
	return (1);
}

int my_putnbr_base_long(long nbr, char *base)
{
	int i = 0;
	int size;
	long nb;

	if (nbr < 0) {
		nbr = - nbr;
		i += 1;
		my_put_char('-');
	}
	size = my_strlen(base);
	if (nbr > 0) {
		nb = nbr;
		nbr /= size;
		i += my_putnbr_base_long(nbr, base);
		i += 1;
		my_put_char(base[nb % size]);
	}
	return (i);
}