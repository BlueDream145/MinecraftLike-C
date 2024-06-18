/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Change block relief
*/

#include	"world.h"

int		change_block_relief(map_t *map, float vector)
{
	static void	(*fcts[9])(map_t *, float) = {
		change_up, change_left, change_right, change_down,
		change_up_left, change_up_right, change_down_left,
		change_down_right, NULL
	};
	static int	pts[5]= {
		P_TOP_FRONT_LEFT, P_TOP_FRONT_RIGHT,
		P_TOP_BACK_RIGHT, P_TOP_BACK_LEFT, -1
	};

	if (map->selected_id == -1)
		return (ERROR);	
	apply_change(map->selected, pts, vector, map);
	for (int i = 0; fcts[i]; i++)
		fcts[i](map, vector);
	return (SUCCESS);
}

void		apply_change(block_t *block, int *pts, float vector, map_t *map)
{
	for (int i = 0; pts[i] != -1; i++)
		block->pts[pts[i]].y += vector;
	for (block_t *tmp = block; tmp && tmp->next; tmp = tmp->next)
		fill_sub_block(tmp->next, tmp, map);
}

void		change_up(map_t *map, float vector)
{
	static int	pts[3] = { P_TOP_FRONT_LEFT, P_TOP_FRONT_RIGHT, -1 };
	int		pos = map->selected_id + map->size;
	
	if (pos >= map->size * map->size)
		return;
	apply_change(&map->blocks[map->selected_id + map->size],
			pts, vector, map);
}

void		change_down(map_t *map, float vector)
{
	static int	pts[3] = { P_TOP_BACK_LEFT, P_TOP_BACK_RIGHT, -1 };
	int		pos = map->selected_id - map->size;

	if (pos < 0)
		return;
	apply_change(&map->blocks[map->selected_id - map->size],
			pts, vector, map);
}

void		change_left(map_t *map, float vector)
{
	static int	pts[3] = { P_TOP_FRONT_RIGHT, P_TOP_BACK_RIGHT, -1 };
	int		pos = map->selected_id - 1;

	if (pos < 0 || map->selected_id % map->size == 0)
		return;
	apply_change(&map->blocks[map->selected_id - 1], pts, vector, map);
}