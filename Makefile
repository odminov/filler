#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahonchar <ahonchar@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/10 20:30:11 by ahonchar          #+#    #+#              #
#    Updated: 2019/03/10 20:30:13 by ahonchar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

FLAGS = -Wextra -Wall -Werror

SRC = main.c

D_OBJ = obj/

D_SRC = src/

D_INC = inc/

OBJ = $(addprefix $(D_OBJ), $(SRC:.c=.o))

NAME = ahonchar.filler

LIB = ./libft/libft.a

all: libcomile $(NAME)

libcomile:
	@make -C ./libft

$(D_OBJ)%.o:$(D_SRC)%.c $(D_INC)header.h
	$(CC) $(FLAGS) -c $< -o $@
	
$(NAME): $(D_OBJ) $(OBJ) $(LIB)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB)
	@printf "\x1b[32m%s compiled\n\x1b[0m\n" $(NAME)

$(D_OBJ):
	mkdir $@

clean:
	@make -C ./libft $@
	rm -rf $(D_OBJ)

fclean: clean
	@make -C ./libft $@
	rm -rf $(NAME)
	rm -rf *~
	rm -rf \#*\#
re: fclean all