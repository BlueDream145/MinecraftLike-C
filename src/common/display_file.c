/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Display flag
*/

#include	"world.h"

void		display_file(const char *path)
{
	FILE	*file = fopen(path, "r");

	if (!(file))
		return;
	for (char c; fread(&c, 1, 1, file) > 0;)
		write(1, &c, 1);
	fclose(file);
}
