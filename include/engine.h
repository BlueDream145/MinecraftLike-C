/*
** EPITECH PROJECT, 2017
** my_world
** File description:
** Engine main header
*/

#ifndef ENGINE_H_
	#define ENGINE_H_

#include	<math.h>
#include	"genetics.h"
#include	"blocks_vars.h"

#define		C_DEFAULT_BLOCK		B_GRASS
#define		C_DEFAULT_SIZE		16

#define		C_FPS			60

#define		C_FACTOR_X		0.825
#define		C_FACTOR_Y		0.6

#define		C_ROTATION_FACTOR	0.025

#define		C_MAX_WIDTH		1920.0
#define		C_MAX_HEIGHT		1080.0

#define		C_BLOCK_WIDTH		64.0
#define		C_BLOCK_HEIGHT		64.0
#define		C_BLOCK_DEPTH		64.0

#define		C_CAMERA_VX		10
#define		C_CAMERA_VY		10

#define		C_RELIEF_FACTOR		3
#define		C_ZOOM_FACTOR		0.1

#define		C_MAX_ZOOM		5.0
#define		C_MIN_ZOOM		0.5

#define		C_MAX_ROTATION_X	1.0
#define		C_MIN_ROTATION_X	0.2
#define		C_MAX_ROTATION_Y	1.0
#define		C_MIN_ROTATION_Y	0.2

#define		C_MAX_BAR		7
#define		C_MIN_BAR		0

#define		C_ZOOM_INC_KEY		sfKeyE
#define		C_ZOOM_DEC_KEY		sfKeyA

#define		C_ROTATION_X_INC_KEY	sfKeyM
#define		C_ROTATION_X_DEC_KEY	sfKeyK
#define		C_ROTATION_Y_INC_KEY	sfKeyL
#define		C_ROTATION_Y_DEC_KEY	sfKeyO

#define		C_RELIEF_INC_KEY	sfKeyR
#define		C_RELIEF_DEC_KEY	sfKeyT

#define		C_BAR_INC_KEY		sfKeyW
#define		C_BAR_DEC_KEY		sfKeyX

#define		C_REMOVE_KEY		sfKeyG

#define		C_TOP_KEY		sfKeyUp
#define		C_DOWN_KEY		sfKeyDown
#define		C_LEFT_KEY		sfKeyLeft
#define		C_RIGHT_KEY		sfKeyRight

#define		C_TOP2_KEY		sfKeyZ
#define		C_DOWN2_KEY		sfKeyS
#define		C_LEFT2_KEY		sfKeyQ
#define		C_RIGHT2_KEY		sfKeyD

#define		C_ADD_BLOCK_KEY		sfKeySpace

#define		C_MAX_BLOCKS		10

typedef		struct block_s {
	int		id;
	sfVector3f	pts[P_TOTAL];
	sfVertexArray	*faces[F_TOTAL];
	sfVertexArray	*outline;
	int		to_display[F_TOTAL];
	struct block_s	*next;
}		block_t;

typedef		struct block_save_s {
	int		id;
	sfVector3f	pts[P_TOTAL];
	int		blocks[C_MAX_BLOCKS];

}		block_save_t;

typedef		struct map_s {
	block_t		*blocks;
	sfVector2f	camera;
	int		size;
	sfVector3f	block_size;
	int		default_block;
	float		zoom;
	sfTexture	*spritesheet;
	sfRenderStates	states;
	int		selected_id;
	block_t		*selected;
	sfColor		outline_color ;
	sfVector2f	rotation;
	int		to_project;
	int		select_bar;
	int		select_block;
	sfSound		*on_block;
}		map_t;

typedef		struct block_evt_s {
	int		id;
	int		code;
	int		bar;
}		block_evt_t;

// src/engine/engine_manager.c
int		engine_manager(layout_t *, resources_t *, map_t **);
void		update_alert(layout_t *layout, char *text);
int		my_strcmp(char const *s1, char const *s2);

// src/engine/init_map.c
map_t		*get_map(int size, int default_block, resources_t *rsc);

// src/engine/init_map2.c
int		init_map(map_t *, int, int, resources_t *);

// src/engine/destroy_map.c
void		destroy_map(map_t *map);
void		destroy_block(block_t *block);

// src/engine/display_map.c
void		display_map(map_t *map, resources_t *rsc);
void		display_block(block_t *, sfRenderStates *, resources_t *);
void		display_outlines(map_t *map, resources_t *rsc);

// src/engine/project_map.c
void		project_map(map_t *map);
void		project_block(map_t *map, block_t *block);
void		project_face(map_t *map, block_t *block, int j);

// src/engine/project_map2.c
sfVertex	project_point(sfVector3f old, map_t *map);
void		project_outline(map_t *map, block_t *block);
sfVector2f	project_vector2f(sfVector3f old, map_t *map);

// src/engine/render_sort.c
void		set_rendered_faces(map_t *map, int i);

// src/engine/camera.c
void		map_zoom_in(map_t *map);
void		map_zoom_out(map_t *map);

// src/engine/select_block.c
int		select_block(map_t *map, block_t *block, int id);
void		search_select(map_t *map, resources_t *rsc);
void		key_select(map_t *map, sfEvent *event);
int		is_block_clicked(map_t *map, block_t *block, sfVector2i click);

// src/engine/change_relief.c
int		change_block_relief(map_t *map, float vector);
void		apply_change(block_t *, int *, float, map_t *);
void		change_up(map_t *map, float vector);
void		change_down(map_t *map, float vector);
void		change_left(map_t *map, float vector);

// src/engine/change_relief2.c
void		change_right(map_t *map, float vector);
void		change_up_left(map_t *map, float vector);
void		change_up_right(map_t *map, float vector);
void		change_down_left(map_t *map, float vector);
void		change_down_right(map_t *map, float vector);

// src/engine/engine_commands.c
void		engine_events(map_t *map);
void		relief_events(map_t *map);
void		zoom_events(map_t *map);
void		camera_events(map_t *map);

// src/engine/engine_commands2.c
void		rotation_events(map_t *map);
void		engine_events2(map_t *map, resources_t *rsc, layout_t *layout);
void		blocks_events(map_t *map, sfEvent *event, layout_t *layout);
void		blocks_events2(map_t *map, sfEvent *event, layout_t *layout);

// src/engine/contains.c
int		block_contains_point(block_t *, map_t *, sfVector2f);

// src/engine/add_block.c
int		add_block(int id, block_t *block, map_t *map);
void		fill_sub_block(block_t *sub, block_t *block, map_t *map);

// src/engine/remove_block.c
void		remove_block(block_t *block, map_t *map);

// src/engine/block_list.c
block_evt_t	*get_block_evt_list(void);

// src/engine/load_map.c
map_t		*load_map(const char *path, resources_t *rsc);

// src/engine/save_map.c
int		save_map(const char *path, map_t *map);

// src/engine/bint_to_engine.c
void		bind_to_engine(layout_t *layout, map_t *map);

// src/update_bar.c
void		update_bar(map_t *map, layout_t *layout);
void		update_selected(map_t *map, layout_t *layout);

#endif /* !ENGINE_H_ */
