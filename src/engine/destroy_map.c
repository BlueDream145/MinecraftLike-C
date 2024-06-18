/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Destroy map
*/

#include	"world.h"

void		destroy_map(map_t *map)
{
	int	size = 0;

	if (!(map) || !(size = map->size * map->size))
		return;
	if (map->blocks) {
		for (int i = 0; i < size; i++)
			destroy_block(&map->blocks[i]);
		free(map->blocks);
		map->blocks = NULL;
	}
	if (map->spritesheet)
		sfTexture_destroy(map->spritesheet);
	map->spritesheet = NULL;
	free(map);
}

void	destroy_block(block_t *block)
{
	if (block->outline) {
		sfVertexArray_clear(block->outline);
		sfVertexArray_destroy(block->outline);
		block->outline = NULL;
	}
	if (!(block->faces))
		return;
	for (int j = 0; j < F_TOTAL; j++) {
		if (block->faces[j]) {
			sfVertexArray_clear(block->faces[j]);
			sfVertexArray_destroy(block->faces[j]);
			block->faces[j] = NULL;
		}
	}
}