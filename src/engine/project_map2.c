/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Project map 2
*/

#include	"world.h"

void		project_outline(map_t *map, block_t *block)
{
	static int	order[] = {
		0, 1, 2, 3, 0, 4, 5, 6, 7, 4, -1, 1, 5, -1, 6, 2, -1, 3, 7, -2
	};
	sfVertex	vertices[2];

	sfVertexArray_clear(block->outline);
	for (int i = 1; order[i] != -2; i++) {
		if (order[i] == -1) {
			i++;
			continue;
		}
		vertices[0] = project_point(block->pts[order[i - 1]], map);
		vertices[1] = project_point(block->pts[order[i]], map);
		sfVertexArray_append(block->outline, vertices[0]);
		sfVertexArray_append(block->outline, vertices[1]);
	}
}

sfVertex	project_point(sfVector3f old, map_t *map)
{
	sfVertex	new = {
		{ 0, 0 },
		map->outline_color,
		{ 0, 0 }
	};

	new.position.x = (old.x + old.z * map->rotation.x) * map->zoom +
			map->camera.x;
	new.position.y = (old.y - old.z * map->rotation.y) * map->zoom +
			map->camera.y;
	return (new);
}

sfVector2f	project_vector2f(sfVector3f old, map_t *map)
{
	sfVector2f	new = {
		(old.x + old.z * map->rotation.x) * map->zoom + map->camera.x,
		(old.y - old.z * map->rotation.y) * map->zoom + map->camera.y
	};

	return (new);
}