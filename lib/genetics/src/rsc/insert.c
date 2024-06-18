/*
** EPITECH PROJECT, 2017
** Genetics library
** File description:
** Add or remove widget(s) header
*/

#include "genetics.h"


static void	iterate(layout_t *layout, const char *string,
			widget_t *empty, int i);

void insert_widget(layout_t *layout, widget_t widget, int step)
{
	widget.step = step;
	layout->widgets[layout->widgets_len] = widget;
	layout->widgets_len++;
}

int delete_first_widget(layout_t *layout)
{
	int success = FALSE;
	int i;

	for (i = 0; i < layout->widgets_len; i++) {
		if (layout->widgets[i].id == SPRITE)
			sfSprite_destroy(layout->widgets[i].sprite);
		if (layout->widgets[i].id == TEXT)
			sfText_destroy(layout->widgets[i].text);
		free(layout->widgets[i].anims);
		success = TRUE;
		break;
	}
	if (success == TRUE) {
		for (i = i + 1; i < layout->widgets_len; i++)
			layout->widgets[i - 1] = layout->widgets[i];
		layout->widgets_len--;
	}
	return (success);
}

void clear_all_widgets(layout_t *layout)
{
	while (layout->widgets_len != 0)
		delete_first_widget(layout);
}

widget_t get_widget_by_string(layout_t *layout, const char *string)
{
	widget_t empty;

	for (int i = 0; i < layout->widgets_len; i++) {
		iterate(layout, string, &empty, i);
	}
	return (empty);
}

static void	iterate(layout_t *layout, const char *string,
			widget_t *empty, int i)
{
	const char	*temp;

	if (layout->widgets[i].id == TEXT) {
		temp = sfText_getString(layout->widgets[i].text);
		if (my_strncmp(temp, string, my_strlen(string)) == 0)
			*empty = layout->widgets[i];
	}
}