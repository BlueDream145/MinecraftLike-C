/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Display map
*/

#include	"world.h"

void		display_map(map_t *map, resources_t *rsc)
{
	int	size = map->size * map->size;
	int	total = 0;

	if (map->to_project) {
		project_map(map);
		map->to_project = FALSE;
	}
	for (int i = size - map->size; total != size; total++) {
		display_block(&map->blocks[i], &map->states, rsc);
		if (!((i + 1) % map->size) && i != size - map->size)
			i = i - 2 * map->size + 1;
		else
			i++;
	}
	display_outlines(map, rsc);
}

void		display_block(block_t *block, sfRenderStates *states,
				resources_t *rsc)
{
	for (int i = 0; i < F_TOTAL; i++) {
		if (block->to_display[i])
			sfRenderWindow_drawVertexArray(rsc->window,
				block->faces[i], states);
	}
	for (block_t *tmp = block->next; tmp; tmp = tmp->next)
		display_block(tmp, states, rsc);

}

void		display_outlines(map_t *map, resources_t *rsc)
{
	block_t	*tmp = &map->blocks[map->selected_id];

	if (map->selected_id == -1)
		return;
	for (; tmp; tmp = tmp->next)
		sfRenderWindow_drawVertexArray(rsc->window, tmp->outline, NULL);
}