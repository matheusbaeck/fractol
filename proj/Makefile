# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: math42 <math42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 23:11:40 by mamagalh@st       #+#    #+#              #
#    Updated: 2023/08/27 16:18:20 by math42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = clang

SRCS =  main.c render.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror #-g3 #-fsanitize=address

LFLAGS = -L minilibx-linux -lX11 -lXext -lmlx -lm

all: $(NAME)

$(NAME): libft/libft.a minilibx-linux/libmlx.a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)
	@make clean

libft/libft.a:
	@make -C libft

minilibx-linux/libmlx.a:
	@make -C minilibx-linux

clean: 
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all