/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Project map to isometric view
*/

#include	"world.h"
#include	"engine_const.h"
#include	"engine_textures.h"
#include	"blocks.h"

static sfVector2f	get_textCoords(block_t *block, int i, int j);

void		project_map(map_t *map)
{
	int	size = map->size * map->size;

	for (int i = 0; i < size; i++) {
		project_block(map, &map->blocks[i]);
	}
}

void		project_block(map_t *map, block_t *block)
{
	for (int j = 0; j < F_TOTAL; j++) {
		if (block->to_display[j])
			project_face(map, block, j);
	}
	project_outline(map, block);
	for (block_t *tmp = block->next; tmp; tmp = tmp->next)
		project_block(map, tmp);
}

void		project_face(map_t *map, block_t *block, int j)
{
	sfVertex	vertex;

	sfVertexArray_clear(block->faces[j]);
	for (int i = 0; i < 4; i++) {
		vertex = project_point(block->pts[faces_order[j][i]], map);
		vertex.texCoords = get_textCoords(block, i, j);
		sfVertexArray_append(block->faces[j], vertex);
	}
}

static sfVector2f	get_textCoords(block_t *block, int i, int j)
{
	sfVector2f	pos;

	if (i == 0 || i == 2) {
		pos.x = GET_DIM_X(C_BLOCK_FACES[block->id][j])
			+ C_DIM * (i ? 1 : 0);
		pos.y = GET_DIM_Y(C_BLOCK_FACES[block->id][j])
			+ C_DIM * (i ? 1 : 0);
	} else {
		pos.x = GET_DIM_X(C_BLOCK_FACES[block->id][j])
			+ C_DIM * (i == 1 ? 1 : 0);
		pos.y = GET_DIM_Y(C_BLOCK_FACES[block->id][j])
			+ C_DIM * (i == 3 ? 1 : 0);
	}
	return (pos);
}