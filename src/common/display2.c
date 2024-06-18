/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** Display 2
*/

#include	"world.h"
#include	"engine_textures.h"

void display_permanent(layout_t *layout, resources_t *rsc)
{
	const int permanent = -42;

	insert_widget(layout, get_sprite_widg(get_sprite(get_pos(0, 0),
		RSC_BG), NULL), permanent);
	insert_widget(layout, get_sprite_widg(get_sprite(get_pos(445, 30),
		RSC_LOGO), NULL), permanent);
	insert_widget(layout, get_text_widg(get_text(get_pos(600, 50),
		APP_HEADER, 70, rsc), NULL), permanent);
	insert_widget(layout, get_text_widg(get_text(get_pos(1170, 130),
		APP_BUILD, 30, rsc), NULL), permanent);
}

void display_game(layout_t *layout, resources_t *rsc)
{
	display_single_widgets(layout, rsc);
	display_single_sprites(layout, rsc);
	update_map_size(layout, rsc);
	display_blocks(layout, rsc);
	display_select_block(layout, rsc);
}

void display_select_block(layout_t *layout, resources_t *rsc)
{
	const int	game = 3;
	sfVector2f	scale = { 125 / C_DIM, 125 / C_DIM };
	sfIntRect	rect = { 0, 0, C_DIM, C_DIM };
	widget_t widg = get_block_widg(get_sprite(get_pos(1460,
			840), C_SP_PATH), NULL, NULL, 1);

	widg.selected = 12;
	sfSprite_setScale(widg.sprite, scale);
	sfSprite_setTextureRect(widg.sprite, rect);
	insert_widget(layout, widg, game);
	insert_widget(layout,
		get_text_widg(get_text(get_pos(1400, 960),
		"Selected block", 30, rsc), NULL), game);
}

void display_blocks(layout_t *layout, resources_t *rsc)
{
	const int	game = 3;
	int		display = 1;
	sfVector2f	scale = { 125 / C_DIM, 125 / C_DIM };
	sfIntRect	rect = { 0, 0, C_DIM, C_DIM };
	widget_t	widg;

	for (int i = 0; i < 10; i++) {
		widg = get_block_widg(get_sprite(get_pos(100 + (125 * i),
			840), C_SP_PATH), NULL, NULL, display);
		sfSprite_setScale(widg.sprite, scale);
		sfSprite_setTextureRect(widg.sprite, rect);
		insert_widget(layout, widg, game);
	}
	for (int i = 1; i < 11; i++) {
		widg = get_text_widg(get_text(get_pos(144 + (125 * (i - 1)),
			960), my_itc(i), 30, rsc), NULL);
		if (i == 10)
			i = 0;
		sfText_setString(widg.text,  my_itc(i));
		insert_widget(layout, widg, game);
		if (i == 0)
			return;
	}
}

widget_t get_block_widg(sfSprite *sprite, sfText *text,
	anim_t *anims, int display)
{
	widget_t widg;

	widg.id = BLOCK;
	widg.sprite = sprite;
	widg.text = text;
	widg.anims = anims;
	widg.data = NULL;
	widg.display = display;
	return (widg);
}