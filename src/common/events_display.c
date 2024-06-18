/*
** EPITECH PROJECT, 2018
** My World
** File description:
** Display events
*/

#include "world.h"

static void	try_save(layout_t *layout, map_t *map);

void zoom_in(layout_t *layout, resources_t *rsc, void *target)
{
	map_t	*map = target;

	if (layout == NULL || rsc == NULL || target == NULL)
		return;
	map_zoom_in(map);
}

void zoom_out(layout_t *layout, resources_t *rsc, void *target)
{
	map_t	*map = target;

	if (layout == NULL || rsc == NULL || target == NULL)
		return;
	map_zoom_out(map);
}

void leave(layout_t *layout, resources_t *rsc, void *target)
{
	map_t	*map = target;

	if (layout == NULL || rsc == NULL || target == NULL)
		return;
	try_save(layout, map);
	layout->selected_map = "Unknow map.txt";
	update_map_name(layout);
	layout->step--;
}

static void	try_save(layout_t *layout, map_t *map)
{
	char	*strs[3] = { "maps/\0", layout->selected_map, NULL };
	char	*path;

	if (map) {
		path = my_concat(strs);
		my_put_str("Trying to save map..\n");
		if (save_map(path, map))
			my_put_str("Map saved !\n");
		else
			my_put_str("Can't save map..\n");
	}
}