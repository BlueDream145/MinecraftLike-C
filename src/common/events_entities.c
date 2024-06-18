/*
** EPITECH PROJECT, 2018
** My World
** File description:
** Entities events
*/

#include "world.h"

void delete_entity(layout_t *layout, resources_t *rsc, void *target)
{
	map_t	*map = target;

	if (layout == NULL || rsc == NULL || target == NULL)
		return;
	if (map->selected)
		remove_block(map->selected, map);
}

void create_entity(layout_t *layout, resources_t *rsc, void *target)
{
	map_t	*map = target;

	if (layout == NULL || rsc == NULL || target == NULL)
		return;
	if (map->selected) {
		add_block(map->select_block, map->selected, map);
		sfSound_play(rsc->sound);
	}
}

void relief_in(layout_t *layout, resources_t *rsc, void *target)
{
	map_t	*map = target;

	if (map == NULL || layout == NULL || rsc == NULL || target == NULL)
		return;
}

void relief_out(layout_t *layout, resources_t *rsc, void *target)
{
	map_t	*map = target;

	if (map == NULL || layout == NULL || rsc == NULL || target == NULL)
		return;
}