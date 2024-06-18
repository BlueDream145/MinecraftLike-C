/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Event manager
*/

#include	"world.h"

void		event_manager(resources_t *rsc, layout_t *layout, map_t *map)
{
	while (sfRenderWindow_pollEvent(rsc->window, &rsc->event)) {
		manage_events(layout, rsc);
		if (layout->step == 3 && map)
			engine_events2(map, rsc, layout);
	}
	if (layout->step == 3 && map)
		engine_events(map);
}