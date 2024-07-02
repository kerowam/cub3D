# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 23:20:55 by gfredes-          #+#    #+#              #
#    Updated: 2024/07/02 18:14:56 by gfredes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

#BONUS = 

CFLAGS = -Wall -Wextra -Werror

CLEAN = rm -f

SRC =	main.c \
		check_args.c \
		free.c \
		init.c \
		map.c \
		colors_and_textures.c \
		error.c \
		check_map.c \
		map_size.c \
		
#SRC_BONUS =	

CC = gcc -g

OBJT = $(SRC:.c=.o)

OBJT_BONUS = $(SRC_BONUS:.c=.o)

LIBFT = libft/libft.a

#MINILIBX = minilibx_macos/libmlx.a

all: $(LIBFT) $(NAME)
#Pending to add MLX-42

$(LIBFT):
	make -C ./libft

#$(MINILIBX):
#	make -C ./minilibx_macos

#$(NAME): $(LIBFT) $(MINILIBX) $(OBJT)
#	$(CC) $(CFLAGS) $(SRC) $(MINILIBX) $(LIBFT) -lGL -lX11 -lXext -lm -o $(NAME)

# For Mac

$(NAME): $(LIBFT) $(OBJT)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

bonus: $(BONUS)

#$(BONUS): $(LIBFT) $(MINILIBX) $(OBJT_BONUS)
#s	$(CC) $(CFLAGS) $(SRC_BONUS) $(MINILIBX) $(LIBFT) -lGL -lX11 -lXext -lm -o $(BONUS)

# For Mac

#$(BONUS): $(LIBFT) $(MINILIBX) $(OBJT_BONUS)
#	$(CC) $(CFLAGS) $(SRC_BONUS) $(MINILIBX) $(LIBFT) -framework OpenGL -framework AppKit -o $(BONUS)

clean:
	$(CLEAN) $(OBJT)
#$(OBJT_BONUS)
	make -C ./libft clean
#	make -C ./minilibx_macos clean

fclean: clean
	$(CLEAN) $(NAME) $(BONUS)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re bonus