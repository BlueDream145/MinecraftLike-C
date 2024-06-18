/*
** EPITECH PROJECT, 2017
** Genetics library
** File description:
** Get basic instances
*/

#include "genetics.h"

sfSprite *get_sprite(sfVector2f pos, const char *file_path)
{
	sfSprite *sprite = sfSprite_create();

	sfSprite_setTexture(sprite, sfTexture_createFromFile(
		file_path, NULL), sfTrue);
	sfSprite_setPosition(sprite, pos);
	return (sprite);
}

sfText *get_text(sfVector2f pos, const char *value,
	const int size, resources_t *rsc)
{
	sfText *text = sfText_create();

	sfText_setPosition(text, pos);
	sfText_setString(text, value);
	sfText_setFont(text, rsc->font);
	sfText_setColor(text, sfWhite);
	sfText_setCharacterSize(text, size);
	return (text);
}

sfIntRect get_rect(const int top, const int left, const int width,
	const int height)
{
	sfIntRect rect;

	rect.top = top;
	rect.left = left;
	rect.width = width;
	rect.height = height;
	return (rect);
}

sfVector2i get_size(const int width, const int height)
{
	sfVector2i vector;

	vector.x = width;
	vector.y = height;
	return (vector);
}

sfVector2f get_pos(const int x, const int y)
{
	sfVector2f vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}