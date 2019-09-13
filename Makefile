# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: badhont <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/13 17:23:13 by badhont           #+#    #+#              #
#    Updated: 2019/03/14 22:57:05 by badhont          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = clang

CFLAGS = -Wall -Wextra -Werror

SRCS =	srcs/main.c \
		srcs/mouse_events.c \
		srcs/ft_keyboard.c \
		srcs/ft_init.c \
		srcs/ft_put_settings.c \
		srcs/ft_mandelbrot.c \
		srcs/ft_julia.c \
		srcs/ft_gland.c \
		srcs/ft_batman.c \
		srcs/ft_set_color.c \
		srcs/ft_put_usage.c \

OBJS =	$(SRCS:.c=.o)

INCLUDES = includes/

MLX = -lmlx -framework OpenGL -framework AppKit

PTHREAD = -l pthread

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
		make -C ./libft/
		$(CC) $(CFLAGS) -o $(NAME) libft/libft.a \
		$(OBJS) -I $(INCLUDES) $(MLX) $(PTHREAD)

libft/libft.a :
	make -C libft/

%.o: %.c $(INCLUDES)fractol.h Makefile
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INCLUDES)

clean:
	rm -f $(OBJS) && make -C libft/ clean

fclean: clean
	rm -f $(NAME) && make -C libft/ fclean

re: fclean all
