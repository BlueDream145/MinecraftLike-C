/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Engine user commands
*/

#include	"world.h"

void		engine_events(map_t *map)
{
	camera_events(map);
	zoom_events(map);
	relief_events(map);
	rotation_events(map);
}

void		relief_events(map_t *map)
{
	if (sfKeyboard_isKeyPressed(C_RELIEF_INC_KEY)) {
		change_block_relief(map, C_RELIEF_FACTOR);
		map->to_project = TRUE;
	}
	if (sfKeyboard_isKeyPressed(C_RELIEF_DEC_KEY)) {
		change_block_relief(map, -C_RELIEF_FACTOR);
		map->to_project = TRUE;
	}
}

void		zoom_events(map_t *map)
{
	if (sfKeyboard_isKeyPressed(C_ZOOM_INC_KEY) && map->zoom < C_MAX_ZOOM) {
		map->zoom += C_ZOOM_FACTOR;
		map->camera.x -= map->block_size.x * map->zoom;
		map->camera.y += map->block_size.y * map->zoom / 2;
		map->to_project = TRUE;
	}
	if (sfKeyboard_isKeyPressed(C_ZOOM_DEC_KEY) && map->zoom > C_MIN_ZOOM) {
		map->zoom -= C_ZOOM_FACTOR;
		map->camera.x += map->block_size.x * map->zoom;
		map->camera.y -= map->block_size.y * map->zoom / 2;
		map->to_project = TRUE;
	}
}

void		camera_events(map_t *map)
{
	float	factor	= 1;
	float	zoom	= map->zoom > 1 ? map->zoom : 1;

	if (sfKeyboard_isKeyPressed(sfKeyLShift))
		factor *= 3;
	if (sfKeyboard_isKeyPressed(C_LEFT_KEY)
		&& map->camera.x > -(map->size * map->block_size.x * 2
			* zoom)) {
		map->camera.x -= C_CAMERA_VX * factor;
		map->to_project = TRUE;
	}
	if (sfKeyboard_isKeyPressed(C_RIGHT_KEY)
		&& map->camera.x < map->size * map->block_size.x * 3
			* zoom) {
		map->camera.x += C_CAMERA_VX * factor;
		map->to_project = TRUE;
	}
	if (sfKeyboard_isKeyPressed(C_TOP_KEY)
		&& map->camera.y > -(map->size * (map->block_size.y / 2)
			* zoom)) {
		map->camera.y -= C_CAMERA_VY * factor;
		map->to_project = TRUE;
	}
	if (sfKeyboard_isKeyPressed(C_DOWN_KEY)
		&& map->camera.y < map->size * map->block_size.y * 3
			* zoom) {
		map->camera.y += C_CAMERA_VY * factor;
		map->to_project = TRUE;
	}
}