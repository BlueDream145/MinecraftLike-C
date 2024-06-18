/*
** EPITECH PROJECT, 2017
** Genetics library
** File description:
** Resize window
*/

#include "genetics.h"

void resized_event(layout_t *layout, resources_t *rsc)
{
	double w;
	double h;

	if (layout == NULL || rsc == NULL)
		return;
	w = rsc->event.size.width;
	h = rsc->event.size.height;
	layout->ratio_x = w / 1920;
	layout->ratio_y = h / 1080;
	layout->size = get_size(rsc->event.size.width, rsc->event.size.height);
}