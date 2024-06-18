/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Remove block
*/

#include	"world.h"

void		remove_block(block_t *block, map_t *map)
{
	block_t	*tmp = block->next;
	block_t *last = block;

	for (; tmp && tmp->next; last = tmp, tmp = tmp->next);
	if (tmp) {
		destroy_block(tmp);
		last->next = NULL;
	}
	map->to_project = TRUE;
}
