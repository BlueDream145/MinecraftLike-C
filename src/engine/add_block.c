/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Add block to map
*/

#include	"world.h"

static block_t	*get_sub(int id, block_t *block, map_t *map);
static void	link_sub(block_t *sub, block_t *block);

int		add_block(int id, block_t *block, map_t *map)
{
	block_t	*sub = NULL;
	int	i = 0;

	for (; block && block->next; block = block->next, i++);
	if (i >= C_MAX_BLOCKS)
		return (SUCCESS);
	if (!(sub = get_sub(id, block, map)))
		return (ERROR);
	link_sub(sub, block);
	map->to_project = TRUE;
	return (SUCCESS);
}

static block_t	*get_sub(int id, block_t *block, map_t *map)
{
	block_t	*sub = malloc(sizeof(block_t));

	if (!(sub))
		return (NULL);
	sub->id = id;
	sub->next = NULL;
	if (!(sub->outline = sfVertexArray_create()))
		return (NULL);
	sfVertexArray_setPrimitiveType(sub->outline, sfLines);
	for (int i = 0; i < F_TOTAL; i++) {
		if (!(sub->faces[i] = sfVertexArray_create()))
			return (NULL);
		sfVertexArray_setPrimitiveType(sub->faces[i], sfQuads);
		sub->to_display[i] = block->to_display[i];
	}
	sub->to_display[F_FRONT] = TRUE;
	sub->to_display[F_RIGHT] = TRUE;
	fill_sub_block(sub, block, map);
	project_block(map, block);
	return (sub);

}

static void	link_sub(block_t *sub, block_t *block)
{
	block_t	*tmp = block->next;

	for (; tmp && tmp->next; tmp = tmp->next);
	if (tmp)
		tmp->next = sub;
	else
		block->next = sub;
}

void	fill_sub_block(block_t *sub, block_t *block, map_t *map)
{
	for (int i = 0; i < 4; i++) {
		sub->pts[i] = block->pts[i];
		sub->pts[i].y -= map->block_size.y;
		sub->pts[i + 4] = block->pts[i];
	}
}