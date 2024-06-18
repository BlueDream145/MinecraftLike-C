/*
** EPITECH PROJECT, 2017
** Genetics library
** File description:
** Put string or number header
*/

#include "genetics.h"

void my_put_char(char c)
{
	write(1, &c, 1);
}

void my_put_str(const char *str)
{
	int length = 0;

	while (str[length] != '\0') {
		my_put_char(str[length]);
		length++;
	}
}

void my_put_nbr(int nb)
{
	if (nb > 9)
		my_put_nbr(nb / 10);
	else if (nb < 0) {
		nb = nb * -1;
		write(1, "-", 1);
		my_put_nbr(nb / 10);
	}
	my_put_char(nb % 10 + '0');
}

int my_put_float(double nbr)
{
	long dec;
	long ent;
	double dec2;
	int i = 0;

	ent = nbr;
	dec = nbr * (float)1000000;
	dec -= ent * 1000000;
	dec2 = (double)dec;
	i += my_putnbr_base_long(ent, "0123456789");
	i++;
	my_put_char('.');
	i += my_putnbr_base_long((long)dec2, "0123456789");
	return (i);
}