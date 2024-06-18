/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Engine commands 2
*/

#include	"world.h"

void		rotation_events(map_t *map)
{
	if (sfKeyboard_isKeyPressed(C_ROTATION_X_INC_KEY)
		&& map->rotation.x < C_MAX_ROTATION_X) {
		map->rotation.x += C_ROTATION_FACTOR;
		map->to_project = TRUE;
	}
	if (sfKeyboard_isKeyPressed(C_ROTATION_X_DEC_KEY)
		&& map->rotation.x > C_MIN_ROTATION_X) {
		map->rotation.x -= C_ROTATION_FACTOR;
		map->to_project = TRUE;
	}
	if (sfKeyboard_isKeyPressed(C_ROTATION_Y_INC_KEY)
		&& map->rotation.y < C_MAX_ROTATION_Y) {
		map->rotation.y += C_ROTATION_FACTOR;
		map->to_project = TRUE;
	}
	if (sfKeyboard_isKeyPressed(C_ROTATION_Y_DEC_KEY)
		&& map->rotation.y > C_MIN_ROTATION_Y) {
		map->rotation.y -= C_ROTATION_FACTOR;
		map->to_project = TRUE;
	}
}

void		engine_events2(map_t *map, resources_t *rsc, layout_t *layout)
{
	if (rsc->event.type == sfEvtMouseButtonPressed)
		search_select(map, rsc);
	blocks_events(map, &rsc->event, layout);
	blocks_events2(map, &rsc->event, layout);
	key_select(map, &rsc->event);
}

void		blocks_events(map_t *map, sfEvent *event, layout_t *layout)
{
	block_evt_t	*list = get_block_evt_list();

	if (!(event->type == sfEvtKeyPressed))
		return;
	for (int i = 0; i < B_TOTAL; i++) {
		if (list[i].bar == map->select_bar &&
			event->key.code == list[i].code) {
			map->select_block = list[i].id;
			update_selected(map, layout);
		}
	}
	if (event->key.code == C_ADD_BLOCK_KEY && map->selected) {
		add_block(map->select_block, map->selected, map);
		sfSound_play(map->on_block);
	}
}

void		blocks_events2(map_t *map, sfEvent *event, layout_t *layout)
{
	if (!(event->type == sfEvtKeyPressed))
		return;
	if (event->key.code == C_REMOVE_KEY)
		remove_block(map->selected, map);
	if (event->key.code == C_BAR_INC_KEY && map->select_bar < C_MAX_BAR) {
		map->select_bar++;
		update_bar(map, layout);
	}
	if (event->key.code == C_BAR_DEC_KEY && map->select_bar > C_MIN_BAR) {
		map->select_bar--;
		update_bar(map, layout);
	}
}