#	Root path
ROOT		=		./

#	Sources path
F_SRC		=		$(ROOT)src/

#	Binary name
NAME		=		my_world

#	Common sources
SRC		=		$(F_SRC)common/display_menu.c \
				$(F_SRC)common/display_update.c \
				$(F_SRC)common/display.c \
				$(F_SRC)common/display2.c \
				$(F_SRC)common/events_display.c \
				$(F_SRC)common/events_entities.c \
				$(F_SRC)common/events_map.c \
				$(F_SRC)common/main.c \
				$(F_SRC)common/map.c \
				$(F_SRC)common/global_events.c	\
				$(F_SRC)common/display_components.c	\
				$(F_SRC)common/display_file.c

#	Engine sources
SRC		+=		$(F_SRC)engine/engine_manager.c	\
				$(F_SRC)engine/project_map.c	\
				$(F_SRC)engine/project_map2.c	\
				$(F_SRC)engine/init_map.c	\
				$(F_SRC)engine/init_map2.c	\
				$(F_SRC)engine/destroy_map.c	\
				$(F_SRC)engine/display_map.c	\
				$(F_SRC)engine/render_sort.c	\
				$(F_SRC)engine/camera.c	\
				$(F_SRC)engine/select_block.c	\
				$(F_SRC)engine/change_relief.c	\
				$(F_SRC)engine/change_relief2.c	\
				$(F_SRC)engine/engine_commands.c	\
				$(F_SRC)engine/engine_commands2.c	\
				$(F_SRC)engine/contains.c	\
				$(F_SRC)engine/add_block.c	\
				$(F_SRC)engine/remove_block.c	\
				$(F_SRC)engine/block_list.c	\
				$(F_SRC)engine/load_map.c	\
				$(F_SRC)engine/save_map.c	\
				$(F_SRC)engine/bind_to_engine.c	\
				$(F_SRC)engine/update_bar.c

#	Compile every source file to .o
OBJ		=		$(SRC:.c=.o)

#	Compiler
CC		=		cc

#	Compilation flags
CFLAGS		+=		-Wall -Werror -Wextra -pedantic -std=c99	\
				-I $(ROOT)include/ -ggdb3 -O0

#	Libraries links
LDFLAGS		+=		-lc_graph_prog -L $(ROOT)lib -lgenetics -l m

#	Call compilation rule
all:				$(NAME)

#	Compile every file then pack them all !
$(NAME):			$(OBJ)
				make -C $(ROOT)lib/genetics
				$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LDFLAGS)

#	Compile with g3 flag
debug:				fclean $(OBJ)
				make -C $(ROOT)lib/genetics
				$(CC) -o $(NAME) $(CFLAGS) -g3 $(OBJ) $(LDFLAGS)

#	Clean object type sources
clean:
				rm -f $(OBJ)
				make -C $(ROOT)lib/genetics clean

#	Clean binary
fclean:				clean
				rm -f $(NAME)
				make -C $(ROOT)lib/genetics fclean

#	Clean all then compile
re:				fclean all

.PHONY:				all clean fclean re