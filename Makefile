# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabr <gabrgarc@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/08 11:35:53 by gabr              #+#    #+#              #
#    Updated: 2025/12/08 12:06:55 by gabr             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft/includes

SRCS = $(shell find *.c)

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

$(LIBFT):
	if [ ! -d "$(LIBFT_DIR)" ]; then \
		git clone https://github.com/GabrielGem/42_libft.git libft; \
	fi
	$(MAKE) -sC $(LIBFT_DIR) all

clean:
	$(MAKE) -sC $(LIBFT_DIR) clean

fclean:
	rm $(NAME)
	$(MAKE) -sC $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
