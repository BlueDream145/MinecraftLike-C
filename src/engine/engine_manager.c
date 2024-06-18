/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Engine manager
*/

#include	"world.h"

static int	try_load(layout_t *layout, resources_t *rsc, map_t **map);

int		engine_manager(layout_t *layout, resources_t *rsc, map_t **map)
{
	if (layout->step != 3) {
		if (*map) {
			destroy_map(*map);
			*map = NULL;
		}
		return (SUCCESS);
	}
	if (!(*map)) {
		if (!(try_load(layout, rsc, map)))
			return (ERROR);
		bind_to_engine(layout, *map);
		update_bar(*map, layout);
	}
	display_map(*map, rsc);
	return (SUCCESS);
}

static int	try_load(layout_t *layout, resources_t *rsc, map_t **map)
{
	char	*strs[3] = { "maps/", layout->selected_map, NULL };
	char	*path = my_concat(strs);

	if (!(path))
		return (SUCCESS);
	*map = load_map(path, rsc);
	if (!(*map) && layout->map_size && !(*map = get_map(layout->map_size,
		C_DEFAULT_BLOCK, rsc))) {
		update_alert(layout, "Default map created");
		return (ERROR);
	}
	return (SUCCESS);
}

void update_alert(layout_t *layout, char *text)
{
	const char *default_text = "Map loaded.";
	const char *tmp = NULL;

	for (int i = 0; i < layout->widgets_len; i++) {
		if (layout->widgets[i].id != TEXT ||
		(tmp = sfText_getString(layout->widgets[i].text)) == NULL)
			continue;
		if (my_strcmp(tmp, default_text) == 0 ||
			my_strcmp(tmp, "Cant load map") == 0 ||
			my_strcmp(tmp, "Default map created") == 0)
			sfText_setString(layout->widgets[i].text, text);
	}
}

int my_strcmp(char const *s1, char const *s2)
{
	int i = 0;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++);
	return (s1[i] - s2[i]);
}