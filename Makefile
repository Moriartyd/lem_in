# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 13:09:12 by cpollich          #+#    #+#              #
#    Updated: 2019/09/26 21:50:16 by cpollich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= lem-in
F		= -Wall -Wextra -Werror

LIBFT_DIR		= ./libft
LIBFT_INC_DIR	= $(LIBFT_DIR)/inc
SRC_DIR			= ./src
INC_DIR			= ./inc
OBJ_DIR			= ./obj
OBJS			= $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))
LEM_H			= $(INC_DIR)/lem_in.h

LIBFT			= $(LIBFT_DIR)/libft.a

SRC	=	parse_input.c parse_input2.c	\
		room_memory.c rooms_memory.c	\
		smezhnost.c sort_nodes.c		\
		errors.c 						\
		bfs.c 							\
		queue.c lemin_main.c stacks.c	\
		find_levels.c 					\
		pathlen.c paths.c remove_forks.c\

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS) $(LEM_H)
	@echo "\033[35mCompiling ./lem-in\033[0m"
	@gcc $(LIBFT) $F $(OBJS) -o $(NAME)
	@echo "\033[1;32m./lem-in was built\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LEM_H)
	@gcc $(FLAGS) -c -g $< -I$(INC_DIR) -I$(LIBFT_INC_DIR) -o $@

$(LIBFT):
	@make -C libft

clean:
	@make -C libft clean
	@rm -Rf $(OBJ_DIR)
	@echo "\033[3;36mProject cleaned\033[0m"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "\033[3;36mProject fully cleaned\033[0m"

re: fclean all

test: $(LIBFT) $(SRC_DIR)/*.c main.c
	gcc -g $F main.c src/* -I./inc -I./libft/inc libft/libft.a -o test

rm:
	rm -Rf test* *.dSYM

.PHONY: all clean fclean re test
