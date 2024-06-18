/*
** EPITECH PROJECT, 2018
** Genetics library
** File description:
** Events widgets
*/

#include "genetics.h"

static int iterate(layout_t *, resources_t *, sfVector2f, int);

void event_maps_widgets(layout_t *layout, resources_t *rsc, sfVector2f mouse)
{
	for (int i = 0; i < layout->widgets_len; i++) {
		if (!(iterate(layout, rsc, mouse, i)))
			break;
	}
}

static int iterate(layout_t *layout, resources_t *rsc,
			sfVector2f mouse, int i)
{
	if (layout->widgets[i].step != layout->step)
		return (SUCCESS);
	if (layout->widgets[i].id == BUTTON && widget_contains_point(
		layout, layout->widgets[i], mouse) == TRUE) {
		if (layout->widgets[i].pointer != NULL) {
			(*layout->widgets[i].pointer)(layout, rsc,
				layout->widgets[i].data);
			return (ERROR);
		} else if (layout->widgets[i].action == EXIT)
			layout->running = FALSE;
		layout->step += layout->widgets[i].action;
		return (ERROR);
	}
	if (layout->widgets[i].id == TEXTBOX && text_contains_point(layout,
		layout->widgets[i], mouse, get_pos(250, 40)) == TRUE)
		layout->widgets[i].selected = 1;
	else if (layout->widgets[i].id == TEXTBOX)
		layout->widgets[i].selected = 0;
	return (SUCCESS);
}
void event_trackbar(layout_t *layout, sfVector2f mouse)
{
	sfVector2f pos;

	for (int i = 0; i < layout->widgets_len; i++) {
		if (layout->widgets[i].step != layout->step)
			continue;
		if (layout->widgets[i].id == TRACKBAR &&
			widget_contains_point(layout, layout->widgets[i],
			get_pos(mouse.x, mouse.y)) == TRUE &&
			mouse.x >= 750 && mouse.x <= 1160) {
			pos = sfSprite_getPosition(layout->widgets[i].sprite);
			sfSprite_setPosition(layout->widgets[i].sprite,
				get_pos(mouse.x + 50, pos.y));
		}
		if (layout->widgets[i].id == TRACKBAR && widget_contains_point
		(layout, layout->widgets[i], get_pos(mouse.x - 32, mouse.y))
			== TRUE && mouse.x >= 750 && mouse.x <= 1250) {
			pos = sfSprite_getPosition(layout->widgets[i].sprite);
			sfSprite_setPosition(layout->widgets[i].sprite,
				get_pos(mouse.x - 50, pos.y));
		}
	}
}

void event_maps_texts(layout_t *layout, resources_t *rsc, sfVector2f mouse)
{
	for (int i = 0; i < rsc->maps_len; i++) {
		if (rsc->maps_fields[i].text == NULL)
			continue;
		if (text_contains_point(layout, rsc->maps_fields[i], mouse,
			get_pos(250, 40)) == TRUE) {
			rsc->maps_fields[i].selected = 1;
			sfText_setStyle(rsc->maps_fields[i].text, sfTextBold);
		}
		else {
			rsc->maps_fields[i].selected = 0;
			sfText_setStyle(rsc->maps_fields[i].text,
				sfTextRegular);
		}
	}
}