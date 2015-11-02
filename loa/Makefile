#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/15 04:10:08 by ymonfray          #+#    #+#              #
#    Updated: 2015/05/15 04:10:08 by ymonfray         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = loa

SRC =	src/loa_list.c\
		src/loa_main.c\
		src/loa_draw.c\
		src/loa_init.c

INC = -I include -I libft/include -I /opt/X11/include/X11

# HEAD = include/loa.h

FW = -framework OpenGL -framework AppKit

LIB = -L libft/ -lft -L minilibx_macos/ -lmlx 

OBJ = $(SRC:.c=.o)

FLAG = -O1

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) -o $(NAME) $(OBJ) $(INC) $(LIB) $(FW)

%.o: %.c
	$(CC) $(FLAG) $(INC) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all