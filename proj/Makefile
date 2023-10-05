# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 23:11:40 by mamagalh@st       #+#    #+#              #
#    Updated: 2023/10/05 19:56:47 by mamagalh@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = clang

SRCS =  main.c render.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -O3 -Wall -Wextra #-Werror #-g3 #-fsanitize=address

LFLAGS = -lmlx -framework OpenGL -framework AppKit -L minilibx

all: $(NAME)

$(NAME): minilibx/libmlx.a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

libft/libft.a:
	@make -C libft

minilibx-linux/libmlx.a:
	@make -C minilibx

clean: 
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all