##
## Makefile for  in /home/Quentss/Work/graphic/tekadventure/parse
## 
## Made by Quentin AMARAL
## Login   <Quentss@epitech.net>
## 
## Started on  Wed May 24 21:52:46 2017 Quentin AMARAL
## Last update Sun May 28 20:42:35 2017 Quentin AMARAL
##

PRINTF  =       @printf

CC	=	gcc

RM	=	rm -f

SRCS	=	src/main.c			\
		src/get_next_line.c		\
		src/load.c			\
		src/my_string.c			\
		src/load_game_basic.c		\
		src/get_next_line_comment.c	\
		src/str_to_wordtab_util.c	\
		src/str_to_wordtab.c		\
		src/my_getnbr.c			\
		src/create_pic.c		\
		src/start_game.c		\
		src/print_cursor.c		\
		src/event_mouse.c		\
		src/load_launcher.c		\
		src/load_game_window.c		\
		src/load_page.c			\
		src/my_game.c			\
		src/chara.c			\
		src/load_room.c			\
		src/load_chara.c		\
		src/change_room.c		\
		src/load_game_door.c		\
		src/load_objects.c		\
		src/print_to_search.c		\
		src/objects.c			\
		src/load_enemy.c		\
		src/enemy.c			\
		src/my_itoa.c			\
		src/my_strcat.c			\
		src/my_strlen.c			\
		src/lose_win.c			\
		src/boss.c			\
		src/aff_instruction.c		\
		src/my_sleep.c			\
		src/aff_scroller.c		\
		src/music.c			\
		src/load_room_bis.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	tekadventure

CFLAGS	+=	-Wall -Wextra -Werror -I includes


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -lc_graph_prog_full
	$(PRINTF) '\033[1;32m> Program Compiled\033[0m\n'

clean:
	$(RM) $(OBJS)
	$(PRINTF) '\033[1;35m> Directory cleaned\033[0m\n'

fclean: clean
	$(RM) $(NAME)
	$(PRINTF) '\033[1;35m> Remove executable\033[0m\n'

re: fclean all

.PHONY: all clean fclean re
