# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 13:09:12 by cpollich          #+#    #+#              #
#    Updated: 2019/09/13 18:34:18 by cpollich         ###   ########.fr        #
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
LIBFT_SRC_DIR	= $(LIBFT_DIR)/src
LIBFT_OBJ_DIR	= $(LIBFT_DIR)/obj
LIBFT_OBJS		= $(addprefix $(LIBFT_OBJ_DIR)/,$(LIBFT_SRC:%.c=%.o))
LIBFT_SRC		= ft_memset.c \
		ft_bzero.c ft_memcpy.c ft_memccpy.c	ft_memmove.c ft_memchr.c ft_memcmp.c\
		ft_strcmp.c ft_strncmp.c ft_strcpy.c ft_strncpy.c ft_strlen.c ft_strdup.c \
		ft_strstr.c ft_strnstr.c ft_atoi.c ft_strcat.c ft_strncat.c ft_strlcat.c\
		ft_strchr.c ft_strrchr.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_iswhitespace.c\
		ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_putchar.c ft_putchar_fd.c \
		ft_putstr.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
		ft_itoa.c ft_strclr.c ft_memalloc.c ft_memdel.c ft_striter.c ft_striteri.c \
		ft_strnew.c ft_strdel.c ft_strequ.c ft_strnequ.c ft_strmap.c ft_strmapi.c\
		ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_strtrimchr.c\
		ft_lstnew.c	ft_lstdelone.c ft_lstdel.c	ft_lstadd.c ft_lstiter.c ft_lstmap.c\
		ft_realloc.c ft_lstsize.c ft_intpower.c ft_abs.c ft_strchr_safe.c ft_strdup_safe.c\
		ft_strshift.c get_next_line.c ft_wordcount.c ft_lstclr.c ft_copyuntil.c \
		ft_doublestrdel.c ft_swap.c

all: $(NAME)

$(NAME): $(LIBFT)

$(LIBFT): $(LIBFT_OBJ_DIR) $(LIBFT_OBJS)
	@ar rc $(LIBFT) $(LIBFT_OBJS)
	@ranlib $(LIBFT)
	@echo "\033[1;32mlibft was built\033[0m"

$(LIBFT_OBJ_DIR):
	@mkdir -p $(LIBFT_OBJ_DIR)

$(LIBFT_OBJ_DIR)/%.o: $(LIBFT_SRC_DIR)/%.c
	@gcc $F -c $< -I$(INC) -o $@

clean:
	@rm -Rf $(LIBFT_OBJ_DIR)
	@echo "\033[3;36mProject cleaned\033[0m"

fclean: clean
	@rm -Rf $(LIBFT)
	@echo "\033[3;36mProject fully cleaned\033[0m"

re: fclean all

test:
	gcc -g main.c src/* libft/libft.a -I./inc -I./libft/include -o test
