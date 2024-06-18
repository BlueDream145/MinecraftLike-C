/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Change relief 2
*/

#include	"world.h"

void		change_right(map_t *map, float vector)
{
	static int	pts[3] = { P_TOP_FRONT_LEFT, P_TOP_BACK_LEFT, -1 };
	int		pos = map->selected_id + 1;

	if (pos >= map->size * map->size || pos % map->size == 0)
		return;
	apply_change(&map->blocks[map->selected_id + 1], pts, vector, map);
}

void		change_up_left(map_t *map, float vector)
{
	static int	pts[2] = { P_TOP_FRONT_RIGHT, -1 };
	int		pos = map->selected_id + map->size - 1;

	if (pos >= map->size * map->size || map->selected_id % map->size == 0)
		return;
	apply_change(&map->blocks[map->selected_id + map->size - 1],
			pts, vector, map);
}

void		change_up_right(map_t *map, float vector)
{
	static int	pts[2] = { P_TOP_FRONT_LEFT, -1 };
	int		pos = map->selected_id + map->size + 1;

	if (pos >= map->size * map->size ||
		(map->selected_id + 1) % map->size == 0)
		return;
	apply_change(&map->blocks[map->selected_id + map->size + 1],
			pts, vector, map);
}
void		change_down_left(map_t *map, float vector)
{
	static int	pts[2] = { P_TOP_BACK_RIGHT, -1 };
	int		pos = map->selected_id - map->size - 1;

	if (pos < 0 || map->selected_id % map->size == 0)
		return;
	apply_change(&map->blocks[map->selected_id - map->size - 1],
			pts, vector, map);
}

void		change_down_right(map_t *map, float vector)
{
	static int	pts[2] = { P_TOP_BACK_LEFT, -1 };
	int		pos = map->selected_id - map->size + 1;

	if (pos < 0 || (map->selected_id + 1) % map->size == 0)
		return;
	apply_change(&map->blocks[map->selected_id - map->size + 1],
			pts, vector, map);
}