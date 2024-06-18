/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Camera handling
*/

#include	"world.h"

void		map_zoom_in(map_t *map)
{
	map->zoom += C_ZOOM_FACTOR;
	map->camera.x -= map->block_size.x * map->zoom;
	map->camera.y += map->block_size.y * map->zoom / 2;
	map->to_project = TRUE;
}

void		map_zoom_out(map_t *map)
{
	map->zoom -= C_ZOOM_FACTOR;
	map->camera.x += map->block_size.x * map->zoom;
	map->camera.y -= map->block_size.y * map->zoom / 2;
	map->to_project = TRUE;
}