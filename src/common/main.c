/*
** EPITECH PROJECT, 2017
** Generics library
** File description:
**
*/

#include "world.h"

static void	check_flag(const char *str);
static int	clean_exit(layout_t *layout, resources_t *rsc);

int		main(int ac, char **av, char **env)
{
	if (check_env(env) == 0)
		return (C_EXIT_ERROR);
	layout_t *layout = get_layout();
	resources_t *rsc = get_resources(layout, RSC_FONT);

	if (ac >= 3) {
		my_put_str("./my_world -h for usage\n");
		return (C_EXIT_SUCCESS);
	} else if (ac == 2) {
		check_flag(av[1]);
		return (C_EXIT_SUCCESS);
	}
	display(layout, rsc);
	return (clean_exit(layout, rsc));
}

int	check_env(char **env)
{
	for (int i = 0; env[i]; i++)
		if (my_strncmp(env[i], "DISPLAY=", 8) == 0)
			return (1);
	return (0);
}

static void	check_flag(const char *str)
{
	if (my_strcmp(str, "-h") == 0)
		display_file(C_README_PATH);
}

static int	clean_exit(layout_t *layout, resources_t *rsc)
{
	int	ret = layout->error ? C_EXIT_ERROR : C_EXIT_SUCCESS;

	for (int i = 0; i < layout->widgets_len; i++) {
		sfSprite_destroy(layout->widgets[i].sprite);
		sfText_destroy(layout->widgets[i].text);
		free(layout->widgets[i].anims);
	}
	if (rsc->sound != NULL)
		sfSound_destroy(rsc->sound);
	if (rsc->sound_buffer != NULL)
		sfSoundBuffer_destroy(rsc->sound_buffer);
	free(layout->widgets);
	free(layout);
	free(rsc);
	return (ret);
}