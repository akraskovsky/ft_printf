# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 10:53:01 by fprovolo          #+#    #+#              #
#    Updated: 2020/01/24 14:55:30 by fprovolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = ./sources/
SRC_NAME = ft_printf.c parse_format.c get_argument.c get_int.c \
			get_unsigned.c get_string.c get_character.c tools.c set_colors.c
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_PATH = ./objects/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

INCLUDES_PATH = ./includes/

LIBFT_PATH = ./libft/
LIBFT = $(LIBFT_PATH)libft.a

LIB = -lft -L$(LIBFT_PATH)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_PATH) $(OBJ)
	@cp $(LIBFT) ./$(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c ./includes/ft_printf.h
	$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -I $(LIBFT_PATH) -c $< -o $@

$(LIBFT): 
	make -C $(LIBFT_PATH)

clean:
	/bin/rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(LIBFT)

re: fclean all
