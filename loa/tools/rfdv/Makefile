#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymonfray <ymonfray@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/29 19:55:57 by ymonfray          #+#    #+#              #
#    Updated: 2015/09/29 19:57:46 by ymonfray         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = RFDV

SRC = rfdv_2.c

INC = -I include -I lib -I libft/includes

LIB = -L libft/ -lft -L lib/ -lgmp

OBJ = $(SRC:.c=.o)

FLAG = 

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) -o $(NAME) $(OBJ) $(INC) $(LIB)

%.o: %.c
	$(CC) $(FLAG) $(INC) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all