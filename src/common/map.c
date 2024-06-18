/*
** EPITECH PROJECT, 2018
** My World
** File description:
** Create / Remove / List maps files
*/

#include "layout.h"

void play_map(layout_t *layout, resources_t *rsc, void *target)
{
	widget_t widg;
	int found = FALSE;

	if (layout == NULL || rsc == NULL || (target = NULL) != NULL)
		return;
	for (int i = 0; i < rsc->maps_len; i++)
		if (rsc->maps_fields[i].selected == 1) {
			widg = rsc->maps_fields[i];
			found = TRUE;
			break;
		}
	if (found == FALSE || widg.text == NULL)
		return;
	layout->selected_map = my_strdup(sfText_getString(widg.text));
	if (layout->selected_map)
		update_map_name(layout);
	layout->step++;
}

void delete_map(layout_t *layout, resources_t *rsc, void *target)
{
	const char *content;
	char *file_path = NULL;
	widget_t widg;
	int found = FALSE;

	for (int i = 0; i < rsc->maps_len; i++)
		if (rsc->maps_fields[i].selected == 1) {
			widg = rsc->maps_fields[i];
			found = TRUE;
			break;
		}
	if (layout == NULL || found == FALSE || widg.text == NULL
		|| (target = NULL) != NULL)
		return;
	content = sfText_getString(widg.text);
	file_path = malloc(sizeof(char) *
		(my_strlen(content) + my_strlen("./maps/") + 1));
	my_strcpy(file_path, "./maps/");
	my_strcat(file_path, content);
	list_maps(rsc);
}

void list_maps(resources_t *rsc)
{
	const int max_maps = 99;
	const char *map_directory = "./maps";
	DIR *rep = opendir(map_directory);
	struct dirent *reader;
	int i = 0;

	rsc->maps_fields = malloc(sizeof(widget_t) * max_maps);
	rsc->maps_len = 0;
	if (rsc->maps_fields == NULL)
		return;
	while ((reader = readdir(rep))) {
		if (reader->d_name[0] == '.')
			continue;
		rsc->maps_fields[rsc->maps_len] =
			get_textbox_widg(get_pos(500, 300 + (40 * i)),
			rsc, reader->d_name);
		rsc->maps_len++;
		i++;
	}
	closedir(rep);
}