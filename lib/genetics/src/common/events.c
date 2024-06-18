/*
** EPITECH PROJECT, 2017
** Genetics library
** File description:
** Manage events close / key / mouse
*/

#include "genetics.h"

static int	iterate(layout_t *layout, resources_t *rsc, int i);

void manage_events(layout_t *layout, resources_t *rsc)
{
	if (rsc->event.type == sfEvtClosed)
		close_event(layout, rsc);
	if (rsc->event.type == sfEvtKeyPressed)
		key_pressed_event(layout, rsc);
	if (rsc->event.type == sfEvtMouseButtonPressed)
		mouse_pressed_event(layout, rsc);
	if (rsc->event.type == sfEvtMouseMoved)
		mouse_moved_event(layout, rsc);
	if (rsc->event.type == sfEvtResized)
		resized_event(layout, rsc);
}

void close_event(layout_t *layout, resources_t *rsc)
{
	if (layout == NULL || rsc == NULL)
		return;
	layout->running = FALSE;
	sfRenderWindow_close(rsc->window);
}

void key_pressed_event(layout_t *layout, resources_t *rsc)
{
	if (layout == NULL || rsc == NULL)
		return;
	for (int i = 0; i < layout->widgets_len; i++) {
		if (layout->widgets[i].step != layout->step)
			continue;
		if (!(iterate(layout, rsc, i)))
			break;
	}
}


static int	iterate(layout_t *layout, resources_t *rsc, int i)
{
	if (layout->widgets[i].id == TEXTBOX &&
		layout->widgets[i].selected == 1) {
		if ((rsc->event.key.code <= 57 && rsc->event.key.code >= 0)
			|| rsc->event.key.code == 59)
			interpret_key_code(layout,
				layout->widgets[i], rsc->event.key);
		return (ERROR);
	}
	return (SUCCESS);
}