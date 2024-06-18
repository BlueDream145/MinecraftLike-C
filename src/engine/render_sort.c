/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Render sort
*/

#include	"world.h"

void	set_rendered_faces(map_t *map, int i)
{
	int	to_display[F_TOTAL] = {
		TRUE,
		FALSE,
		FALSE,
		i < map->size ? TRUE : FALSE,
		FALSE,
		!((i + 1) % map->size) ? TRUE : FALSE
	};
	
	for (int j = 0; j < F_TOTAL; j++)
		map->blocks[i].to_display[j] = to_display[j];
}