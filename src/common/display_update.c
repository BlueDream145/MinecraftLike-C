/*
** EPITECH PROJECT, 2018
** My World
** File description:
** Update widgets
*/

#include "layout.h"

void update_map_name(layout_t *layout)
{
	if (layout == NULL)
		return;
	for (int i = 0; i < layout->widgets_len; i++) {
		if (layout->widgets[i].id == TEXTBOX && layout->selected_map) {
			sfText_setString(layout->widgets[i].text,
				layout->selected_map);
			break;
		}
	}
}

void update_map_size(layout_t *layout, resources_t *rsc)
{
	const char *header = "Map size:       ";
	const char *footer = " x ";
	sfText *text = get_widget_by_string(layout, header).text;
	char *size = my_itc(layout->map_size);
	char *result = malloc(sizeof(char) * (my_strlen(header) +
		my_strlen(footer) + (my_strlen(size) * 2) + 1));

	if (layout == NULL || rsc == NULL || size == NULL || text == NULL
		|| result == NULL)
		return;
	my_strcpy(result, header);
	my_strcat(result, size);
	my_strcat(result, footer);
	my_strcat(result, size);
	sfText_setString(text, result);
}