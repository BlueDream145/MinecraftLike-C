/*
** EPITECH PROJECT, 2018
** My World
** File description:
** Load widgets
*/

#include "layout.h"

static void	iterate(layout_t *layout, int i);

void display(layout_t *layout, resources_t *rsc)
{
	list_maps(rsc);
	display_permanent(layout, rsc);
	display_start_menu(layout, rsc);
	display_settings(layout, rsc);
	display_load_map(layout, rsc);
	display_game(layout, rsc);
	display_window(layout, rsc);

}

void display_window(layout_t *layout, resources_t *rsc)
{
	sfClock *clock = sfClock_create();
	map_t	*map = NULL;

	sfRenderWindow_setFramerateLimit(rsc->window, C_FPS);
	layout->running = TRUE;
	while (sfRenderWindow_isOpen(rsc->window) && layout->running == TRUE) {
		sfRenderWindow_clear(rsc->window, sfBlack);
		event_manager(rsc, layout, map);
		if (!(engine_manager(layout, rsc, &map))) {
			layout->error = TRUE;
			break;
		}
		display_widgets(layout, rsc);
		display_maps(layout, rsc);
		manage_particule(layout, rsc, clock);
		sfRenderWindow_display(rsc->window);
		if (layout->step <= 1)
			list_maps(rsc);
	}
	clear_all_widgets(layout);
	destroy_map(map);
}

void manage_particule(layout_t *layout, resources_t *rsc, sfClock *clock)
{
	if (rsc == NULL || clock == NULL || layout->step != 0)
		return;
	for (int i = 0; i < layout->widgets_len; i++) {
		iterate(layout, i);
	}
}

static void	iterate(layout_t *layout, int i)
{
	sfVector2f current;
	static int pos[6] = { 50, 200, 250, 1400, 1550, 1700 };

	if (layout->widgets[i].id == PARTICULE &&
		layout->widgets[i].sprite != NULL) {
		current = sfSprite_getPosition(
			layout->widgets[i].sprite);
		if (current.y >= 1080) {
			sfSprite_setPosition(layout->widgets[i]
			.sprite, get_pos(pos[crand(0, 6)], -100));
			return;
		}
		current.y += 6;
		sfSprite_setPosition(layout->widgets[i].sprite, current);
	}
}