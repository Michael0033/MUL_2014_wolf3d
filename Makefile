##
## Makefile for Makefile in /home/besnai_m/rendu/Igraph/MUL_2014_fdf
## 
## Made by michael besnainou
## Login   <besnai_m@epitech.net>
## 
## Started on  Fri Dec  5 13:25:26 2014 michael besnainou
## Last update Fri Jan  2 18:38:09 2015 michael besnainou
##

SRC	= wolf3d.c \
	gere_options.c \
	color_manage.c

SRCS	= lib/my/my_putchar.c \
	lib/my/my_putstr.c \
	lib/my/my_strlen.c

CC	= gcc

FILE	= wolf3d

NAME	= libmy.a

OBJ	= $(SRC:.c=.o)

OBJS	= $(SRCS:.c=.o)

RM	= rm -f

LDFLAGS	= -L/usr/lib64 -lmlx -L/usr/lib64/X11 -lXext -lX11 -L./lib -lm

CFLAGS	=-I/usr/X11R6/include -O3 -Wall -Wextra

all: $(NAME) $(FILE)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(FILE): $(OBJ)
	$(CC) -o $(FILE) $(OBJ) $(NAME) $(LDFLAGS)

clean: 
	$(RM) $(OBJ)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(FILE)

re: fclean all

.PHONY: all clean fclean re
