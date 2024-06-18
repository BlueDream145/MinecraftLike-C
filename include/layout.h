/*
** EPITECH PROJECT, 2017
** my_world
** File description:
** layout management header
*/

#ifndef LAYOUT_H_
	#define LAYOUT_H_

#include "genetics.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "engine.h"

// display_components.c
void display_single_sprites(layout_t *layout, resources_t *rsc);
void display_single_widgets(layout_t *layout, resources_t *rsc);
void display_panel(layout_t *layout, resources_t *rsc);
void display_relief(layout_t *layout, resources_t *rsc);

// display_menu.c
void display_start_menu(layout_t *layout, resources_t *rsc);
void display_settings(layout_t *layout, resources_t *rsc);
void display_load_map(layout_t *layout, resources_t *rsc);
void display_particule(layout_t *layout);

// display_update.c
void update_map_name(layout_t *layout);
void update_map_size(layout_t *layout, resources_t *rsc);

// display.c
void display(layout_t *layout, resources_t *rsc);
void display_window(layout_t *layout, resources_t *rsc);
void display_permanent(layout_t *layout, resources_t *rsc);
void manage_particule(layout_t *layout, resources_t *rsc, sfClock *clock);

// display2.c
void display_game(layout_t *layout, resources_t *rsc);
void display_blocks(layout_t *layout, resources_t *rsc);
void display_select_block(layout_t *layout, resources_t *rsc);
widget_t get_block_widg(sfSprite *sprite, sfText *text,
	anim_t *anims, int display);

// events_display.c
void zoom_in(layout_t *layout, resources_t *rsc, void *target);
void zoom_out(layout_t *layout, resources_t *rsc, void *target);
void leave(layout_t *layout, resources_t *rsc, void *target);

// events_entities.c
void delete_entity(layout_t *layout, resources_t *rsc, void *target);
void create_entity(layout_t *layout, resources_t *rsc, void *target);
void relief_in(layout_t *layout, resources_t *rsc, void *target);
void relief_out(layout_t *layout, resources_t *rsc, void *target);

// events_map.c
void map_size_more(layout_t *layout, resources_t *rsc, void *target);
void map_size_less(layout_t *layout, resources_t *rsc, void *target);

// global_events.c
void		event_manager(resources_t *rsc, layout_t *layout, map_t *map);

// bonus/map.c
void list_maps(resources_t *rsc);
void play_map(layout_t *layout, resources_t *rsc, void *target);
void delete_map(layout_t *layout, resources_t *rsc, void *target);

#endif /* !LAYOUT_H_ */
