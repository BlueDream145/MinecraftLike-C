/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Load map
*/

#include	"world.h"

static int	load_block(block_t *block, FILE *fd, map_t *map);
static int	get_map_size(FILE *fd);
static map_t	*clean_exit(FILE *fd);

map_t		*load_map(const char *path, resources_t *rsc)
{
	map_t	*map = (path ? malloc(sizeof(map_t)) : NULL);
	FILE	*fd = (path ? fopen(path, "rb") : NULL);
	int	size = (path ? get_map_size(fd) : 0);

	if (!(path) || !(map) || !(size)
		|| !(map = get_map(size, B_GRASS, rsc)))
		return (clean_exit(fd));
	size *= size;
	for (int i = 0; i < size; i++) {
		if (!(load_block(&map->blocks[i], fd, map)))
			return (clean_exit(fd));
	}
	map->to_project = TRUE;
	fclose(fd);
	return (map);
}

static int	load_block(block_t *block, FILE *fd, map_t *map)
{
	block_save_t	save;

	if (!(fread(&save, sizeof(block_save_t), 1, fd)))
		return (ERROR);
	for (int i = 0; i < P_TOTAL; i++)
		block->pts[i] = save.pts[i];
	for (int i = 0; save.blocks[i] != -1; i++) {
		add_block(save.blocks[i], block, map);
	}
	return (SUCCESS);
}

static int	get_map_size(FILE *fd)
{
	int	size = 0;

	if (!(fd) || !(fread(&size, sizeof(int), 1, fd)))
		return (0);
	return (size);
}

static map_t	*clean_exit(FILE *fd)
{
	if (fd)
		fclose(fd);
	return (NULL);
}