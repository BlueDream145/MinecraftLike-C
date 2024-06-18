/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Contains functions
*/

#include	"world.h"

static double		get_width(sfVector2f center, sfVector2f pos);
static sfVector2f	get_center(block_t *block, map_t *map);

int		block_contains_point(block_t *block, map_t *map, sfVector2f pos)
{
	sfVector2f	center = get_center(block, map);
	double x1	= get_width(center, pos);
	double x2	= get_width(center,
		project_vector2f(block->pts[4], map));

	if (x1 <= x2)
		return (TRUE);
	return (FALSE);
}

static sfVector2f	get_center(block_t *block, map_t *map)
{
	sfVector2f	pos[2] = {
		project_vector2f(block->pts[4], map),
		project_vector2f(block->pts[6], map)
	};
	sfVector2f	res = {
		(pos[1].x + pos[0].x) / 2,
		(pos[1].y + pos[0].y) / 2
	};

	return (res);
}

static double		get_width(sfVector2f center, sfVector2f pos)
{
	return (sqrt(pow(center.x - pos.x, 2) + pow(center.y- pos.y, 2)));
}