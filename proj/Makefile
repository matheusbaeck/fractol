# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 23:11:40 by mamagalh@st       #+#    #+#              #
#    Updated: 2023/10/24 22:40:58 by mamagalh@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = clang

SRCS =  main.c render.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -O3 -Wall -Wextra #-Werror #-g3 #-fsanitize=address

LFLAGS = -lft -lmlx -framework OpenGL -framework AppKit -L minilibx -L libft

all: $(NAME)

$(NAME): libft/libft.a minilibx/libmlx.a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

libft/libft.a:
	@make -C libft

minilibx/libmlx.a:
	@make -C minilibx

clean: 
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

ffclean: fclean
	@make clean -C minilibx
	@make clean -C libft

re: fclean all