/*
** EPITECH PROJECT, 2018
** My World
** File description:
** Display components
*/

#include "layout.h"

void display_single_sprites(layout_t *layout, resources_t *rsc)
{
	const int game = 3;
	widget_t exit_widg = get_button_widg(get_sprite(get_pos(1690, 870),
	RSC_BUTTON_2), get_text(get_pos(1695, 968), "Leave", 25, rsc), NULL,
		-1);

	exit_widg.pointer = leave;
	insert_widget(layout, exit_widg, game);
	insert_widget(layout, get_sprite_widg(get_sprite(get_pos(7, 8),
		RSC_BASKET), NULL), game);
	insert_widget(layout, get_sprite_widg(get_sprite(get_pos(120, 8),
		RSC_PLUS), NULL), game);
	insert_widget(layout, get_sprite_widg(get_sprite(get_pos(1687, 8),
		RSC_ZOOM_OUT), NULL), game);
	insert_widget(layout, get_sprite_widg(get_sprite(get_pos(1577, 8),
		RSC_ZOOM_IN), NULL), game);
	insert_widget(layout, get_sprite_widg(get_sprite(get_pos(1687, 868),
		RSC_EXIT), NULL), game);
	insert_widget(layout, get_text_widg(get_text(get_pos(230, 10),
		"Map loaded", 25, rsc), NULL), game);
}

void display_single_widgets(layout_t *layout, resources_t *rsc)
{
	const int game = 3;
	widget_t delete_widg = get_button_widg(get_sprite(get_pos(10, 10),
	RSC_BUTTON_2), get_text(get_pos(8, 105), "Delete", 25, rsc), NULL, 1);
	widget_t create_widg = get_button_widg(get_sprite(get_pos(120, 10),
	RSC_BUTTON_2), get_text(get_pos(118, 105), "Create", 25, rsc), NULL,
		1);
	widget_t zoom_in_widg = get_button_widg(get_sprite(get_pos(1580, 10),
	RSC_BUTTON_2), get_text(get_pos(1578, 105), "Zoom +", 25, rsc), NULL,
		1);
	widget_t zoom_out_widg = get_button_widg(get_sprite(get_pos(1690, 10),
	RSC_BUTTON_2), get_text(get_pos(1688, 105), "Zoom -", 25, rsc), NULL,
		1);

	delete_widg.pointer = delete_entity;
	create_widg.pointer = create_entity;
	zoom_out_widg.pointer = zoom_out;
	zoom_in_widg.pointer = zoom_in;
	insert_widget(layout, delete_widg, game);
	insert_widget(layout, create_widg, game);
	insert_widget(layout, zoom_out_widg, game);
	insert_widget(layout, zoom_in_widg, game);
	display_relief(layout, rsc);
}

void display_panel(layout_t *layout, resources_t *rsc)
{
	const int load_map = 2;
	widget_t size_less_widg = get_button_widg(get_sprite(get_pos(1490, 335)
	, RSC_SIZE_LESS), NULL, NULL, -3);
	widget_t size_more_widg = get_button_widg(get_sprite(get_pos(1545, 335)
	, RSC_SIZE_MORE), NULL, NULL, -3);
	widget_t input_widg = get_textbox_widg(get_pos(1370, 422), rsc,
		layout->selected_map);

	size_more_widg.pointer = map_size_more;
	size_less_widg.pointer = map_size_less;
	input_widg.pointer = NULL;
	insert_widget(layout, get_sprite_widg(get_sprite(get_pos(1295, 240),
		RSC_PANEL), NULL), load_map);
	insert_widget(layout, get_text_widg(get_text(get_pos(1335, 300),
		"Map size:       16 x 16", 25, rsc), NULL), load_map);
	insert_widget(layout, get_text_widg(get_text(get_pos(1335, 374),
		"Map name:", 25, rsc), NULL), load_map);
	insert_widget(layout, size_more_widg, load_map);
	insert_widget(layout, size_less_widg, load_map);
	insert_widget(layout, get_sprite_widg(get_sprite(get_pos(1335, 414),
		RSC_INPUT), NULL), load_map);
	insert_widget(layout, input_widg, load_map);
}

void display_relief(layout_t *layout, resources_t *rsc)
{
	const int game = 3;
	widget_t relief_in_widg = get_button_widg(get_sprite(get_pos(1280, 10),
	RSC_BUTTON_2), get_text(get_pos(1278, 105), "Relief +", 25, rsc), NULL,
		1);
	widget_t relief_out_widg = get_button_widg(get_sprite(get_pos(1390, 10),
	RSC_BUTTON_2), get_text(get_pos(1388, 105), "Relief -", 25, rsc), NULL,
		1);

	relief_out_widg.pointer = relief_out;
	relief_in_widg.pointer = relief_in;
	insert_widget(layout, relief_in_widg, game);
	insert_widget(layout, relief_out_widg, game);
	insert_widget(layout, get_sprite_widg(get_sprite(get_pos(1367, 0),
		RSC_ROTATION_LEFT), NULL), game);
	insert_widget(layout, get_sprite_widg(get_sprite(get_pos(1257, 0),
		RSC_ROTATION_RIGHT), NULL), game);
}