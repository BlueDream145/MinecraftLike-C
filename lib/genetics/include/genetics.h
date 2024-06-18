/*
** EPITECH PROJECT, 2017
** Genetics library
** File description:
** Genetics lib main header
*/

#ifndef GENETICS_H_
	#define GENETICS_H_

#include	<SFML/Graphics.h>
#include	<SFML/System.h>
#include	<SFML/Audio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>

#define APP_NAME ("MyWorld")
#define APP_HEADER ("My Amazing World")
#define APP_BUILD ("Version 0.0.1")
#define APP_FOOTER ("Epitech Project CPY 2018 | CSFLM / Genetics library | \
Matthieu / Alexandre")

#define RSC_BG ("./data/background.jpg")
#define RSC_LOGO ("./data/logo.png")
#define RSC_FONT ("./data/Cinzel-Black.otf")
#define RSC_BUTTON ("./data/button.png")
#define RSC_BUTTON_2 ("./data/button_2.png")
#define RSC_PLAY ("./data/play.png")
#define RSC_CREATE ("./data/create.png")
#define RSC_DELETE ("./data/delete.png")
#define RSC_PLUS ("./data/plus.png")
#define RSC_SOUND ("./data/sound.png")
#define RSC_BASKET ("./data/button_basket.png")
#define RSC_ZOOM_IN ("./data/zoom_in.png")
#define RSC_ZOOM_OUT ("./data/zoom_out.png")
#define RSC_EXIT ("./data/exit.png")
#define RSC_PANEL ("./data/panel.png")
#define RSC_SIZE_MORE ("./data/size_plus.png")
#define RSC_SIZE_LESS ("./data/size_less.png")
#define RSC_INPUT ("./data/input.png")
#define RSC_TRACKBAR ("./data/trackbar.png")
#define RSC_BUTTONBAR ("./data/buttonbar.png")
#define RSC_PARTICULE ("./data/particule.png")
#define RSC_ROTATION_LEFT ("./data/rotation_left.png")
#define RSC_ROTATION_RIGHT ("./data/rotation_right.png")

typedef		struct layout_s layout_t;
typedef		struct resources_s resources_t;

typedef		struct anim_s {
	int		current_frame;
	int		max_frame;
	sfVector2i	frame_size;
	sfVector2i	grid;
	int		delay;
}		anim_t;

typedef		struct widget_s {
	int		id;
	sfSprite	*sprite;
	sfText		*text;
	anim_t		*anims;
	int		current_anim;
	int 		step;
	int		action;
	int 		selected;
	void*		data;
	int	display;
	void (*pointer)(layout_t*, resources_t*, void*);
}		widget_t;

struct layout_s {
	widget_t	*widgets;
	sfVector2f	pos;
	sfVector2i	size;
	char		*selected_map;
	char		*alert;
	int		widgets_len;
	int		running;
	int		step;
	int		map_size;
	double		ratio_x;
	double		ratio_y;
	int		error;
};

struct resources_s {
	sfRenderWindow	*window;
	sfFont		*font;
	widget_t	*maps_fields;
	int 		maps_len;
	sfEvent		event;
	sfSound		*sound;
	sfSoundBuffer	*sound_buffer;
};

enum	boolean {
	FALSE	= 0,
	TRUE
};

enum	wigets_type {
	SPRITE	= 0,
	TEXT,
	BUTTON,
	TEXTBOX,
	TRACKBAR,
	PARTICULE,
	BLOCK
};

enum	widgets_action {
	PERMANENT = -42,
	BACK	= -2,
	CURRENT	= -1,
	EXIT 	= 0,
	NEXT,
	LOAD,
};

enum		ret_err {
	ERROR = 0,
	SUCCESS
};

// src/common/events_key.c
void interpret_key_code(layout_t *layout, widget_t widget, sfKeyEvent key);
void add_key(widget_t widget, char c);
void remove_key(widget_t widget);

// src/common/events_widgets.c
void event_maps_widgets(layout_t *layout, resources_t *rsc, sfVector2f mouse);
void event_trackbar(layout_t *layout, sfVector2f mouse);
void event_maps_texts(layout_t *layout, resources_t *rsc, sfVector2f mouse);

// src/common/events.c
void manage_events(layout_t *layout, resources_t *rsc);
void close_event(layout_t *layout, resources_t *rsc);
void key_pressed_event(layout_t *layout, resources_t *rsc);
void mouse_pressed_event(layout_t *layout, resources_t *rsc);
void mouse_moved_event(layout_t *layout, resources_t *rsc);

// src/common/resize.c
void resized_event(layout_t *layout, resources_t *rsc);

// src/rsc/display.c
void display_widgets(layout_t *layout, resources_t *rsc);
void display_maps(layout_t *layout, resources_t *rsc);

// src/rsc/insert.c
void insert_widget(layout_t *layout, widget_t widget, int step);
int delete_first_widget(layout_t *layout);
void clear_all_widgets(layout_t *layout);
widget_t get_widget_by_string(layout_t *layout, const char *string);

// src/rsc/instances.c
layout_t *get_layout(void);
resources_t *get_resources(layout_t *layout, const char *font_path);
widget_t get_particule_widg(sfSprite *sprite);

// src/rsc/widgets.c
widget_t get_trackbar_widg(sfSprite *sprite, anim_t *anims);
widget_t get_sprite_widg(sfSprite *sprite, anim_t *anims);
widget_t get_text_widg(sfText *text, anim_t *anims);
widget_t get_button_widg(sfSprite *sprite, sfText *text, anim_t *anims,
	int action);
widget_t get_textbox_widg(sfVector2f pos, resources_t *rsc, const char *value);

// src/utils/get.c
sfSprite *get_sprite(sfVector2f pos, const char *file_path);
sfText *get_text(sfVector2f pos, const char *value,
	const int size, resources_t *rsc);
sfIntRect get_rect(const int top, const int left, const int width,
	const int height);
sfVector2i get_size(const int width, const int height);
sfVector2f get_pos(const int x, const int y);

// src/utils/point.c
int widget_contains_point(layout_t *layout, widget_t widget, sfVector2f pos);
int text_contains_point(layout_t *layout,
	widget_t widget, sfVector2f pos, sfVector2f size);
int crand(int from, int to);

// src/utils/put_base.c
int my_putnbr_base(int nbr, const char *base);
int my_putnbr_base_long(long nbr, char *base);

// src/utils/put.c
void my_put_char(char c);
void my_put_str(const char *str);
void my_put_nbr(int nb);
int my_put_float(double nbr);

// src/utils/string_extra.c
int my_strncmp(char const *s1, char const *s2, int n);
char *my_itc(int nbr);
int number_digits(int nbr);

// src/utils/string.c
int my_strlen(const char *str);
char *my_strdup(const char *src);
char *my_strcpy(char *dest, const char *src);
char *my_strcat(char *dest, const char *src);
char *my_concat(char **str);

// src/rsc/window.c
float		get_ratioX(resources_t *rsc, float max);
float		get_ratioY(resources_t *rsc, float max);

#endif /* !GENETICS_H_ */
