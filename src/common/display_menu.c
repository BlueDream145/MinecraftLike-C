/*
** EPITECH PROJECT, 2018
** My World
** File description:
** Load menu widgets
*/

#include "layout.h"

void display_start_menu(layout_t *layout, resources_t *rsc)
{
	const int start_menu = 0;

	insert_widget(layout, get_text_widg(get_text(get_pos(440, 930),
		APP_FOOTER, 20, rsc), NULL), start_menu);
	insert_widget(layout, get_button_widg(get_sprite(get_pos(650, 250),
	RSC_BUTTON), get_text(get_pos(780, 280), "PLAY", 70, rsc), NULL,
		LOAD), start_menu);
	insert_widget(layout, get_button_widg(get_sprite(get_pos(850, 450),
	RSC_BUTTON), get_text(get_pos(887, 480), "SETTINGS", 70, rsc), NULL,
		NEXT), start_menu);
	insert_widget(layout, get_button_widg(get_sprite(get_pos(650, 650),
	RSC_BUTTON), get_text(get_pos(780, 680), "EXIT", 70, rsc), NULL,
		EXIT), start_menu);
	display_particule(layout);
}

void display_particule(layout_t *layout)
{
	const int start_menu = 0;

	insert_widget(layout, get_particule_widg(get_sprite(get_pos(50, -700),
		RSC_PARTICULE)), start_menu);
	insert_widget(layout, get_particule_widg(get_sprite(get_pos(200, -600),
		RSC_PARTICULE)), start_menu);
	insert_widget(layout, get_particule_widg(get_sprite(get_pos(250, -500),
		RSC_PARTICULE)), start_menu);
	insert_widget(layout, get_particule_widg(get_sprite(get_pos(1400, -300)
		, RSC_PARTICULE)), start_menu);
	insert_widget(layout, get_particule_widg(get_sprite(get_pos(1550, -200)
		, RSC_PARTICULE)), start_menu);
	insert_widget(layout, get_particule_widg(get_sprite(get_pos(1700, -100)
		, RSC_PARTICULE)), start_menu);
}

void display_settings(layout_t *layout, resources_t *rsc)
{
	const int settings = 1;

	insert_widget(layout, get_sprite_widg(get_sprite(get_pos(400, 200),
		RSC_SOUND), NULL), settings);
	insert_widget(layout, get_button_widg(get_sprite(get_pos(1250, 790),
	RSC_BUTTON), get_text(get_pos(1380, 820), "BACK", 70, rsc), NULL,
		CURRENT), settings);
	insert_widget(layout, get_sprite_widg(get_sprite(get_pos(700, 260),
		RSC_TRACKBAR), NULL), settings);
	insert_widget(layout, get_trackbar_widg(get_sprite(get_pos(700, 255),
		RSC_BUTTONBAR), NULL), settings);
}

void display_load_map(layout_t *layout, resources_t *rsc)
{
	const int load_map_menu = 2;
	widget_t play_widg = get_button_widg(get_sprite(get_pos(400, 740),
	RSC_PLAY), get_text(get_pos(410, 880), "PLAY", 40, rsc), NULL, 23);
	widget_t delete_widg = get_button_widg(get_sprite(get_pos(1000, 740),
	RSC_DELETE), get_text(get_pos(983, 880), "DELETE", 40, rsc), NULL, 24);

	play_widg.pointer = play_map;
	delete_widg.pointer = delete_map;
	insert_widget(layout, get_text_widg(get_text(get_pos(440, 230),
		"Available maps :", 40, rsc), NULL), load_map_menu);
	insert_widget(layout, play_widg, 2);
	insert_widget(layout, get_button_widg(get_sprite(get_pos(700, 740),
	RSC_CREATE), get_text(get_pos(679, 880), "CREATE", 40, rsc), NULL, 1)
		, load_map_menu);
	insert_widget(layout, delete_widg, load_map_menu);
	insert_widget(layout, get_button_widg(get_sprite(get_pos(1250, 790),
	RSC_BUTTON), get_text(get_pos(1380, 820), "BACK", 70, rsc), NULL, BACK)
		, load_map_menu);
	display_panel(layout, rsc);
}