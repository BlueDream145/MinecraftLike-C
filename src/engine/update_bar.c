/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Update bar
*/

#include	"engine.h"
#include	"engine_textures.h"
#include	"blocks.h"

void		update_bar(map_t *map, layout_t *layout)
{
	int		i = 0;
	int		id = 0;
	sfIntRect	rect = { 0, 0, C_DIM, C_DIM };
	int		start = 10 * map->select_bar;

	for (; i < layout->widgets_len && layout->widgets[i].id != BLOCK ; i++);
	for (; i < layout->widgets_len && id < 10 && id + start < B_TOTAL
		&& layout->widgets[i].id == BLOCK; i++, id++) {
		rect.left = GET_DIM_X(C_BLOCK_FACES[start + id][F_FRONT]);
		rect.top = GET_DIM_Y(C_BLOCK_FACES[start + id][F_FRONT]);
		sfSprite_setTextureRect(layout->widgets[i].sprite, rect);
	}
	if (id != 10) {
		rect.left = GET_DIM_X(S_EMPTY);
		rect.top = GET_DIM_Y(S_EMPTY);
		for (; i < layout->widgets_len && id < 10
			&& layout->widgets[i].id == BLOCK; i++, id++) {
			sfSprite_setTextureRect(layout->widgets[i].sprite,
				rect);
		}
	}
}

void		update_selected(map_t *map, layout_t *layout)
{
	sfIntRect	rect = {
		GET_DIM_X(C_BLOCK_FACES[map->select_block][F_FRONT]),
		GET_DIM_Y(C_BLOCK_FACES[map->select_block][F_FRONT]),
		C_DIM,
		C_DIM
	};

	for (int i = 0; i < layout->widgets_len; i++) {
		if (layout->widgets[i].selected == 12)
			sfSprite_setTextureRect(layout->widgets[i].sprite,
				rect);
	}
}