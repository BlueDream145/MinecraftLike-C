/*
** EPITECH PROJECT, 2018
** Genetics
** File description:
** Events 2
*/

#include	"genetics.h"

void mouse_pressed_event(layout_t *layout, resources_t *rsc)
{
	sfVector2f mouse;

	if (layout == NULL || rsc == NULL)
		return;
	mouse = get_pos(rsc->event.mouseButton.x, rsc->event.mouseButton.y);
	event_maps_widgets(layout, rsc, mouse);
	event_maps_texts(layout, rsc, mouse);
}

void mouse_moved_event(layout_t *layout, resources_t *rsc)
{
	sfVector2f mouse;

	if (layout == NULL || rsc == NULL)
		return;
	mouse = get_pos(rsc->event.mouseMove.x, rsc->event.mouseMove.y);
	event_trackbar(layout, mouse);
	for (int i = 0; i < layout->widgets_len; i++) {
		if (layout->widgets[i].step != layout->step)
			continue;
		if (layout->widgets[i].id == BUTTON &&
		widget_contains_point(layout, layout->widgets[i], mouse) ==
			TRUE && layout->widgets[i].text != NULL)
			sfText_setColor(layout->widgets[i].text,
			sfColor_fromRGB(2, 183, 234));
		else if (layout->widgets[i].id == BUTTON &&
			layout->widgets[i].text != NULL)
			sfText_setColor(layout->widgets[i].text, sfWhite);
	}
}