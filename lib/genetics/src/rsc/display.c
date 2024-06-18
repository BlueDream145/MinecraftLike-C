/*
** EPITECH PROJECT, 2017
** Genetics library
** File description:
** Display widgets header
*/

#include "genetics.h"

void display_widgets(layout_t *layout, resources_t *rsc)
{
	for (int i = 0; i < layout->widgets_len; i++) {
		if ((layout->widgets[i].step != layout->step
		&& layout->widgets[i].step > -42) ||
		(layout->step == 3 && layout->widgets[i].step <= -42))
			continue;
		if ((layout->widgets[i].id == SPRITE || layout->widgets[i].id
			== BUTTON || layout->widgets[i].id == TRACKBAR ||
			layout->widgets[i].id == PARTICULE ||
			layout->widgets[i].id == BLOCK) &&
			layout->widgets[i].sprite != NULL)
			sfRenderWindow_drawSprite(rsc->window,
				layout->widgets[i].sprite, NULL);
		if ((layout->widgets[i].id == TEXT || layout->widgets[i].id
			== BUTTON || layout->widgets[i].id == TEXTBOX
			|| layout->widgets[i].id == BLOCK) &&
			layout->widgets[i].text != NULL)
			sfRenderWindow_drawText(rsc->window,
				layout->widgets[i].text, NULL);
	}
}

void display_maps(layout_t *layout, resources_t *rsc)
{
	if (layout->step != 2)
		return;
	for (int i = 0; i < rsc->maps_len; i++) {
		sfRenderWindow_drawText(rsc->window,
			rsc->maps_fields[i].text,
			NULL);
	}
}