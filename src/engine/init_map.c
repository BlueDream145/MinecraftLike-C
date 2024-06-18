/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Init 3D map
*/

#include	"world.h"

static int	init_block(map_t *map, int i);
static int	prepare_blocks(map_t *map);
static map_t	*error(map_t *map);
static void	fill_block(map_t *map, int i);

/*	Initialize empty flat map	*/
map_t		*get_map(int size, int default_block, resources_t *rsc)
{
	map_t		*map = malloc(sizeof(map_t));

	if (!(map) || size <= 0)
		return (error(map));
	if (!(init_map(map, size, default_block, rsc)) ||
			!(prepare_blocks(map)))
		return (error(map));
	return (map);
}

static int	prepare_blocks(map_t *map)
{
	int	size = map->size * map->size;

	if (!(map->blocks = malloc(sizeof(block_t) * size)) ||
			!(map->spritesheet))
		return (ERROR);
	for (int i = 0; i < size; i++) {
		if (!(init_block(map, i)))
			return (ERROR);
	}
	return (SUCCESS);
}

static int	init_block(map_t *map, int i)
{
	block_t	*block = &map->blocks[i];

	block->id = map->default_block;
	block->next = NULL;
	if (!(block->outline = sfVertexArray_create()))
		return (ERROR);
	sfVertexArray_setPrimitiveType(block->outline, sfLines);
	for (int i = 0; i < F_TOTAL; i++) {
		if (!(block->faces[i] = sfVertexArray_create()))
			return (ERROR);
		sfVertexArray_setPrimitiveType(block->faces[i], sfQuads);
	}
	fill_block(map, i);
	set_rendered_faces(map, i);
	project_block(map, block);
	return (SUCCESS);
}

static void	fill_block(map_t *map, int i)
{
	block_t	*block = &map->blocks[i];

	for (int j = 0; j < P_TOTAL; j++) {
		block->pts[j].x = map->block_size.x * (i % map->size);
		block->pts[j].z = map->block_size.z * (i / map->size);
		block->pts[j].y = map->block_size.y *
			(j >= P_DOWN_FRONT_LEFT ? 1 : 0);
		if (j == P_TOP_FRONT_RIGHT || j == P_TOP_BACK_RIGHT ||
			j == P_DOWN_FRONT_RIGHT || j == P_DOWN_BACK_RIGHT)
			block->pts[j].x += map->block_size.x;
		if (j == P_TOP_BACK_RIGHT || j == P_TOP_BACK_LEFT ||
			j == P_DOWN_BACK_RIGHT || j == P_DOWN_BACK_LEFT)
			block->pts[j].z += map->block_size.z;
	}
}

static map_t	*error(map_t *map)
{
	if (map)
		destroy_map(map);
	return (NULL);
	
}