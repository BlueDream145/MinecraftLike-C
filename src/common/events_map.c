/*
** EPITECH PROJECT, 2018
** My World
** File description:
** Map events
*/

#include "layout.h"

void map_size_more(layout_t *layout, resources_t *rsc, void *target)
{
	if (layout == NULL || rsc == NULL || layout->map_size == 16 * 5 ||
		(target = NULL) != NULL)
		return;
	layout->map_size += 16;
	update_map_size(layout, rsc);
}

void map_size_less(layout_t *layout, resources_t *rsc, void *target)
{
	if (layout == NULL || rsc == NULL || layout->map_size == 16 ||
		(target = NULL) != NULL)
		return;
	layout->map_size -= 16;
	update_map_size(layout, rsc);
}