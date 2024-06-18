/*
** EPITECH PROJECT, 2017
** Genetics library
** File description:
** Manipulate points header
*/

#include "genetics.h"

int widget_contains_point(layout_t *layout, widget_t widget, sfVector2f pos)
{
	sfVector2f widg_pos = sfSprite_getPosition(widget.sprite);
	sfIntRect widg_rect = sfSprite_getTextureRect(widget.sprite);

	widg_pos.x *= layout->ratio_x;
	widg_pos.y *= layout->ratio_y;
	widg_rect.width *= layout->ratio_x;
	widg_rect.height *= layout->ratio_y;
	if (pos.x >= widg_pos.x && pos.x <= widg_pos.x + widg_rect.width &&
	pos.y >= widg_pos.y && pos.y <= widg_pos.y + widg_rect.height)
		return (TRUE);
	return (FALSE);
}

int text_contains_point(layout_t *layout,
	widget_t widget, sfVector2f pos, sfVector2f size)
{
	sfVector2f widg_pos;

	if (widget.text == NULL)
		return (FALSE);
	widg_pos = sfText_getPosition(widget.text);
	widg_pos.x *= layout->ratio_x;
	widg_pos.y *= layout->ratio_y;
	size.x *= layout->ratio_x;
	size.y *= layout->ratio_y;
	if (pos.x >= widg_pos.x && pos.x <= widg_pos.x + size.x &&
	pos.y >= widg_pos.y && pos.y <= widg_pos.y + size.y)
		return (TRUE);
	return (FALSE);
}

int crand(int from, int to)
{
	return (rand() % (from - to) + from);
}