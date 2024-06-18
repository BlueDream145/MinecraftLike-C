/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Save map
*/

#include	"world.h"

static int	save_infos(FILE *fd, map_t *map);
static int	save_block(FILE *fd, block_t *block);
static void	fill_block(block_t *block, block_save_t *save);
static int	clean_exit(FILE *fd);

int		save_map(const char *path, map_t *map)
{
	FILE	*fd = fopen(path, "wb");
	int	size = map->size * map->size;

	if (!(fd) || !(save_infos(fd, map))) {
		my_put_str("Save failed\n");
		return (clean_exit(fd));
	}
	for (int i = 0; i < size; i++) {
		if (!(save_block(fd, &map->blocks[i])))
			return (clean_exit(fd));
	}
	fclose(fd);
	return (SUCCESS);
}

static int	save_infos(FILE *fd, map_t *map)
{
	if (!(fwrite(&map->size, sizeof(int), 1, fd)))
		return (ERROR);
	return (SUCCESS);
}

static int	save_block(FILE *fd, block_t *block)
{
	block_save_t	save;

	fill_block(block, &save);
	if (!(fwrite(&save, sizeof(block_save_t), 1, fd)))
		return (ERROR);
	return (SUCCESS);
}

static void	fill_block(block_t *block, block_save_t *save)
{
	int	j = 0;

	save->id = block->id;
	for (int i = 0; i < P_TOTAL; i++)
		save->pts[i] = block->pts[i];
	for (block = block->next; block; block = block->next) {
		save->blocks[j] = block->id;
		j++;
	}
	for (; j < C_MAX_BLOCKS; j++)
		save->blocks[j] = -1;
}

static int	clean_exit(FILE *fd)
{
	if (fd)
		fclose(fd);
	return (ERROR);
}