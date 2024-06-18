/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Select map block
*/

#include	"world.h"

static sfVector2f	convert_2i_2f(sfVector2i v2i);

int		select_block(map_t *map, block_t *block, int id)
{
	if (!(map) || (id != -1 && (id < 0 || id >= map->size * map->size)))
		return (ERROR);
	if (block) {
		map->selected_id = -1;
		map->selected = block;
	} else {
		map->selected_id = id;
		map->selected = &map->blocks[id];
	}
	return (SUCCESS);
}

void		search_select(map_t *map, resources_t *rsc)
{
	int		size;
	sfVector2f	click;
	
	if (!(map) || !(size = map->size * map->size))
		return;
	click = convert_2i_2f(sfMouse_getPositionRenderWindow(rsc->window));
	for (int i = 0; i < size; i++) {
		if (block_contains_point(&map->blocks[i], map, click)) {
			select_block(map, NULL, i);
			return;
		}
	}
}

void		key_select(map_t *map, sfEvent *event)
{
	if (!(map) || !(event->type == sfEvtKeyPressed))
		return;
	if (event->key.code == C_LEFT2_KEY && map->selected_id % map->size) {
		select_block(map, NULL, map->selected_id - 1);
		map->to_project = TRUE;
	}
	if (event->key.code == C_RIGHT2_KEY
		&& (map->selected_id + 1) % map->size) {
		select_block(map, NULL, map->selected_id + 1);
		map->to_project = TRUE;
	}
	if (event->key.code == C_TOP2_KEY && map->selected_id
		+ map->size < map->size * map->size) {
		select_block(map, NULL, map->selected_id + map->size);
		map->to_project = TRUE;
	}
	if (event->key.code == C_DOWN2_KEY && map->selected_id
		- map->size >= 0) {
		select_block(map, NULL, map->selected_id - map->size);
		map->to_project = TRUE;
	}
}

static sfVector2f	convert_2i_2f(sfVector2i v2i)
{
	sfVector2f	v2f = {
		(float)(v2i.x),
		(float)(v2i.y)
	};

	return (v2f);
}