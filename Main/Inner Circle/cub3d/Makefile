NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFLAG = mlx/libmlx.a
FWFLAG = -framework OpenGL -framework AppKit

LIBCUB = libcub.a
MAIN_SRC = main.c
SRCS = main.c\
		common/ft_strrchr.c\
		common/ft_strcmp.c\
		common/ft_split.c\
		common/ft_error.c\
		common/ft_free.c\
		common/ft_strlen.c\
		common/ft_strlen_2d.c\
		common/ft_strdup.c\
		common/ft_strstr.c\
		common/ft_strnstr.c\
		common/ft_atoi.c\
		common/ft_isspace.c\
		common/ft_deg_to_rad.c\
		common/ft_strjoin.c\
		common/ft_strndup.c\
		parser/parse_map.c\
		parser/read_file.c\
		parser/verify_extension.c\
		parser/verify_file_format.c\
		parser/verify_wall_texture_data_format.c\
		parser/verify_ceilling_floor_data_format.c\
		parser/verify_map_data_format.c\
		parser/get_map_info.c\
		parser/get_wall_texture_info.c\
		parser/get_ceilling_floor_info.c\
		parser/get_int_map_info.c\
		parser/is_map_content.c\
		parser/is_spawn_area.c\
		parser/is_only_one_spawn_area.c\
		parser/is_closed_map.c\
		parser/init_mapcomponents.c\
		parser/get_specific_component.c\
		parser/get_map_components.c\
		parser/check_map_flag.c\
		parser/reorder_map_components.c\
		parser/reorder_map_data.c\
		parser/order_is_okay.c\
		executer/execute.c\
		executer/key_handler.c\
		executer/init_cub3d.c\
		executer/move.c\
		executer/rotate.c\
		executer/init_img.c\
		executer/init_texture_arr.c\
		executer/new_canvas.c\
		executer/new_user.c\
		executer/put_pixel.c\
		executer/cast_ray.c\
		executer/draw_line.c\
		executer/expose.c

OBJS = $(SRCS:%.c=%.o)

all : $(NAME)

$(NAME) : $(LIBCUB) $(LIBFLAG)
	$(CC) $(LIBCUB) $(LIBFLAG) $(FWFLAG) $(MAIN_SRC) -o $@

$(LIBFLAG) :
	cd mlx; make

$(LIBCUB) : $(OBJS)
	ar rc $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $^ -o $@

clean :
	rm -rf $(OBJS)

fclean :
	make clean
	rm -rf $(LIBCUB) $(NAME)
	rm -rf $(NAME).dSYM

re :
	make fclean; make all

.PHONY : all clean fclean re
