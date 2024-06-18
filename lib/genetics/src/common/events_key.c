/*
** EPITECH PROJECT, 2018
** My World
** File description:
** Manage key code
*/

#include "genetics.h"

void interpret_key_code(layout_t *layout, widget_t widget, sfKeyEvent key)
{
	char c;

	if (widget.text == NULL)
		return;
	c = key.code;
	if (key.code == 59 && my_strlen(sfText_getString(widget.text)) != 0)
		remove_key(widget);
	if ((key.code < 0 || key.code > 35) && key.code != 57)
		return;
	if (key.code >= 0 && key.code <= 25) {
		c += 97;
		if (key.shift == sfTrue)
			c -= 32;
	}
	if (key.code >= 26 && key.code <= 35)
		c += 22;
	if (key.code == 57)
		c = ' ';
	if (!(my_strlen(sfText_getString(widget.text)) > 20))
		add_key(widget, c);
	layout->selected_map = (char*)sfText_getString(widget.text);
}

void add_key(widget_t widget, char c)
{
	const char *old = sfText_getString(widget.text);
	char *result = malloc(sizeof(char) * (my_strlen(old) + 2));

	if (my_strlen(old) != 0) {
		my_strcpy(result, old);
		result[my_strlen(old)] = c;
		result[my_strlen(old) + 1] = '\0';
	}
	else {
		result[0] = c;
		result[1] = '\0';
	}
	sfText_setString(widget.text, result);
}

void remove_key(widget_t widget)
{
	const char *old = sfText_getString(widget.text);
	char *result;

	if (my_strlen(old) == 0)
		return;
	result = malloc(sizeof(char) * (my_strlen(old) + 1));
	my_strcpy(result, old);
	result[my_strlen(old) - 1] = '\0';
	sfText_setString(widget.text, result);
}