# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 11:25:27 by seojin            #+#    #+#              #
#    Updated: 2022/10/01 16:52:29 by seojin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc
# CFLAGS = -Wall -Werror -Wextra
CFLAGS =
OPENGL_FLAG = -framework OpenGL
APPKIT_FLAG = -framework AppKit

#----------------MLX----------------#
MLX_LIB = ./mlx/libmlx.a
MLX_SRC = ./mlx/mlx_shaders.c\
		./mlx/mlx_new_window.m\
		./mlx/mlx_init_loop.m\
		./mlx/mlx_new_image.m\
		./mlx/mlx_xpm.c\
		./mlx/mlx_int_str_to_wordtab.c
MLX_SRC += ./mlx/mlx_png.c\
		./mlx/mlx_mouse.m
MLX_OBJ1 = $(MLX_SRC:.c=.o)
MLX_OBJ = $(MLX_OBJ1:.m=.o)

#----------------FDF----------------#
FDF_LIB = libfdf.a
FDF_MAIN_SRC = main.c
FDF_SRC = main.c\
			ft_deg_to_rad.c\
			ft_mlx_pixel_put.c\
			ft_draw.c\
			ft_read_map.c\
			ft_exit.c\
			ft_split.c\
			ft_get_len.c\
			ft_atoi.c\
			ft_free.c\
			ft_img_init.c\
			ft_create_coordinate.c\
			ft_connect_dots.c\
			ft_escape.c\
			ft_zoom.c\
			ft_move.c
FDF_OBJ = $(FDF_SRC:.c=.o)

all : $(NAME)

$(NAME) : $(MLX_LIB) $(FDF_LIB) $(GNL_LIB)
	$(CC) $(CFLAGS) $(OPENGL_FLAG) $(APPKIT_FLAG) $^ $(FDF_MAIN_SRC) -o $@

$(MLX_LIB) :
	cd ./mlx; make

$(FDF_LIB) : $(FDF_OBJ)
	ar rc $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $? -o $@

clean :
	rm -f $(MLX_OBJ) $(FDF_OBJ)

fclean : clean
	rm -f $(MLX_LIB) $(FDF_LIB) $(NAME)
	
re : fclean all

.PHONY : all clean fclean re bonus
