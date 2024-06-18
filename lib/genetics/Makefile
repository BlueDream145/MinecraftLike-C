#	Root path
ROOT		=		./

#	Sources path
F_SRC		=		$(ROOT)src

#	Binary name
NAME		=		libgenetics.a

#	Common sources
SRC		=		$(ROOT)src/common/events_key.c \
				$(root)src/common/events_widgets.c \
				$(ROOT)src/common/events.c \
				$(ROOT)src/common/events2.c \
				$(ROOT)src/common/resize.c

#	Ressources sources
SRC		+=		$(ROOT)src/rsc/display.c \
				$(ROOT)src/rsc/insert.c \
				$(ROOT)src/rsc/instances.c \
				$(ROOT)src/rsc/widgets.c \
				$(ROOT)src/rsc/window.c

#	Utils sources
SRC		+=		$(ROOT)src/utils/get.c \
				$(ROOT)src/utils/point.c \
				$(ROOT)src/utils/put_base.c \
				$(ROOT)src/utils/put.c \
				$(ROOT)src/utils/string.c \
				$(ROOT)src/utils/string_extra.c

#	Compile every source file to .o
OBJ		=		$(SRC:.c=.o)

#	Compiler
CC		=		cc

#	Compilation flags
CFLAGS		+=		-Wall -Werror -Wextra -pedantic -std=c99	\
				-I $(ROOT)include/

#	Libraries links
LDFLAGS		+=		-l c_graph_prog

#	Call compilation rule
all:				$(NAME) copy

#	Compile every file then pack them all !
$(NAME):			$(OBJ)
				ar rc -o $(NAME) $(OBJ)

#	Copy the lib
copy:
				cp $(NAME) $(ROOT)..
				cp $(ROOT)include/genetics.h $(ROOT)../../include/

#	Clean object type sources
clean:
				rm -f $(OBJ)

#	Clean binary
fclean:				clean
				rm -f $(ROOT)$(NAME)
				rm -f $(ROOT)../$(NAME)

#	Clean all then compile
re:				fclean all

.PHONY:				all clean fclean re
