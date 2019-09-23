# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 13:09:12 by cpollich          #+#    #+#              #
#    Updated: 2019/09/23 17:39:16 by cpollich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= lem-in
F		= -Wall -Wextra -Werror

LIBFT_DIR		= ./libft
SRC_DIR			= ./src
INC				= ./inc
OBJ				= ./obj
OBJS			= $(addprefix $(OBJ)/,$(SRC:%.c=%.o))

LIBFT			= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT)

$(LIBFT): $(LIBFT_DIR)/src/*.c
	@make -C libft

clean:
	@make -C libft clean
	@echo "\033[3;36mProject cleaned\033[0m"

fclean: clean
	@make -C libft fclean
	@echo "\033[3;36mProject fully cleaned\033[0m"

re: fclean all

test: $(LIBFT) $(SRC_DIR)/*.c main.c
	gcc -g $F main.c src/* -I./inc -I./libft/ libft/libft.a -o test
