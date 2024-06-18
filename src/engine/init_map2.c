/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Init map 2
*/

#include	"world.h"
#include	"engine_textures.h"

static sfVector2f	get_camera(map_t *map, resources_t *rsc);
static sfVector3f	get_block_size(resources_t *rsc);
static sfRenderStates	get_states(map_t *map);
static sfVector2f	get_rotation(void);

int		init_map(map_t *map, int size, int default_block,
				resources_t *rsc)
{
	map->size		= size;
	map->select_bar		= 0;
	map->outline_color	= sfWhite;
	map->zoom		= 1.0;
	map->default_block	= default_block;
	map->to_project		= TRUE;
	map->selected_id	= -1;
	map->selected		= NULL;
	map->block_size		= get_block_size(rsc);
	map->rotation		= get_rotation();
	map->camera		= get_camera(map, rsc);
	map->on_block		= rsc->sound;
	if (!(map->spritesheet	= sfTexture_createFromFile(C_SP_PATH, NULL)))
		return (ERROR);
	map->states		= get_states(map);
	return (SUCCESS);
}

static sfVector2f	get_camera(map_t *map, resources_t *rsc)
{
	sfVector3f	old = {
		map->size * C_BLOCK_DEPTH * get_ratioX(rsc, C_MAX_WIDTH),
		0,
		map->size * C_BLOCK_DEPTH * get_ratioX(rsc, C_MAX_WIDTH)
	};
	sfVector2f	camera = { 0, 0 };
	sfVertex	new;

	map->camera = camera;
	new = project_point(old, map);
	camera.x = (C_MAX_WIDTH / 2 - new.position.x / 2) *
			get_ratioX(rsc, C_MAX_WIDTH);
	camera.y = (C_MAX_HEIGHT / 2 - new.position.y / 2) *
			get_ratioY(rsc, C_MAX_HEIGHT);

	return (camera);
}

static sfVector3f	get_block_size(resources_t *rsc)
{
	sfVector3f	block_size = {
		C_BLOCK_WIDTH * get_ratioX(rsc, C_MAX_WIDTH),
		C_BLOCK_HEIGHT * get_ratioY(rsc, C_MAX_HEIGHT),
		C_BLOCK_DEPTH * get_ratioX(rsc, C_MAX_WIDTH)
	};

	return (block_size);
}

static sfRenderStates	get_states(map_t *map)
{
	sfRenderStates	states = {
		sfBlendAlpha,
		sfTransform_Identity,
		map->spritesheet,
		NULL
	};

	return (states);
}

static sfVector2f	get_rotation(void)
{
	sfVector2f	rotation = { C_FACTOR_X, C_FACTOR_Y };

	return (rotation);
}