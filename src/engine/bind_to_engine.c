/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Bind to engine
*/

#include	"world.h"

void		bind_to_engine(layout_t *layout, map_t *map)
{
	for (int i = 0; i < layout->widgets_len; i++)
		layout->widgets[i].data = map;
}