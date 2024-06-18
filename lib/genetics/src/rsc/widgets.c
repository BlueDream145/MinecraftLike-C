/*
** EPITECH PROJECT, 2017
** Genetics library
** File description:
** Get widgets
*/

#include "genetics.h"

widget_t get_trackbar_widg(sfSprite *sprite, anim_t *anims)
{
	widget_t widg;

	widg.id = TRACKBAR;
	widg.sprite = sprite;
	widg.anims = anims;
	widg.data = NULL;
	return (widg);
}

widget_t get_sprite_widg(sfSprite *sprite, anim_t *anims)
{
	widget_t widg;

	widg.id = SPRITE;
	widg.sprite = sprite;
	widg.anims = anims;
	widg.data = NULL;
	return (widg);
}

widget_t get_text_widg(sfText *text, anim_t *anims)
{
	widget_t widg;

	widg.id = TEXT;
	widg.text = text;
	widg.anims = anims;
	widg.data = NULL;
	return (widg);
}

widget_t get_button_widg(sfSprite *sprite, sfText *text, anim_t *anims,
	int action)
{
	widget_t widg;

	widg.id = BUTTON;
	widg.text = text;
	widg.sprite = sprite;
	widg.anims = anims;
	widg.action = action;
	widg.pointer = NULL;
	widg.data = NULL;
	return (widg);
}

widget_t get_textbox_widg(sfVector2f pos, resources_t *rsc, const char *value)
{
	widget_t widg;

	widg.id = TEXTBOX;
	widg.text = get_text(pos, value, 20, rsc);
	widg.anims = NULL;
	widg.pointer = NULL;
	widg.data = NULL;
	return (widg);
}