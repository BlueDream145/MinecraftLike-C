/*
** EPITECH PROJECT, 2017
** Genetics library
** File description:
** Get struct instances
*/

#include	<SFML/Audio.h>
#include "genetics.h"

layout_t *get_layout(void)
{
	const int max_widget_len = 200;
	layout_t *layout = malloc(sizeof(layout_t));

	if (layout == NULL)
		return (NULL);
	layout->pos = get_pos(0, 0);
	layout->size = get_size(1920, 1080);
	layout->running = FALSE;
	layout->step = 0;
	layout->widgets_len = 0;
	layout->map_size = 16;
	layout->error = FALSE;
	layout->selected_map = "Unknow map.txt";
	layout->ratio_x = layout->ratio_y = 1;
	layout->widgets = malloc(sizeof(widget_t) * max_widget_len);
	layout->alert = NULL;
	if (layout->widgets == NULL)
		return (NULL);
	return (layout);
}

resources_t *get_resources(layout_t *layout, const char *font_path)
{
	const int default_mod = 32;
	resources_t *rsc = malloc(sizeof(resources_t));
	sfVideoMode mode = { layout->size.x, layout->size.y, default_mod };

	rsc->window = sfRenderWindow_create(mode, APP_NAME,
		sfTitlebar | sfClose, NULL);
	rsc->font = sfFont_createFromFile(font_path);
	rsc->maps_len = 0;
	rsc->sound = sfSound_create();
	rsc->sound_buffer = sfSoundBuffer_createFromFile("./data/sound.ogg");
	sfSound_setBuffer(rsc->sound, rsc->sound_buffer);
	return (rsc);
}

widget_t get_particule_widg(sfSprite *sprite)
{
	widget_t widg;

	widg.id = PARTICULE;
	widg.sprite = sprite;
	widg.anims = NULL;
	return (widg);
}