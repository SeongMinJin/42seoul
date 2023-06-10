/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:55:44 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:43 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include "../mlx/mlx.h"
# include "struct.h"
# include "define.h"

/*-----common-----*/
int			ft_strcmp(char *s1, char *s2);
int			ft_strlen(char *s);
int			ft_strlen_2d(char **str);
int			ft_atoi(char *str);
int			ft_isspace(char c);
void		ft_free_str_2d(char **str);
void		ft_error(int flag);
char		*ft_strdup(char *str);
char		*ft_strstr(char *haystack, char *needle);
char		*ft_strnstr(char *haystack, char *needle, int len);
char		*ft_strrchr(char *str, char c);
char		**ft_split(char *s, char c);
double		ft_deg_to_rad(double degree);

char		*ft_strjoin(char *s1, char *s2);
char		*ft_strndup(char *str, size_t size);

/*-----parser-----*/
int			is_map_content(char c);
int			is_spawn_area(char c);
void		is_only_one_spawn_area(t_map *map);
void		is_closed_map(t_map *map);

void		get_map(t_map *map, char *file_data);
void		get_wall_texture_info(t_map *map, char **file_data);
void		get_ceilling_floor_info(t_map *map, char **file_data);
void		get_int_map(t_map *map, char **file_data);

void		verify_cub_extension(char *file_name);
void		verify_xpm_extension(char *file_name);
char		*verify_file_format(char *file_data);
void		verify_map_data_format(char *file_data);
char		*verify_wall_texture_data_format(char *file_data);
char		*verify_ceilling_floor_data_format(char *file_data);

char		*read_file(char	*file_name);
t_map		*parse_map(char *file_name);

void		init_mapcomponents(t_mapcontents *map);
char		*get_specific_component(t_mapcontents *map, char *temp, int code);
void		get_map_components(t_mapcontents *map, char *file_data, \
int *index, char *keyword);
int			check_map_flag(t_mapcontents *map);
char		*reorder_map_components(t_mapcontents *temp, \
char *file_data, int data_pos);
char		*reorder_map_data(char *file_data);
int			order_is_okay(char *file_data);
int			is_okay(char *file_data, int *i, char *type);
int			is_okay_fc(char *file_data, int *i);

/*----executer----*/
void		execute(t_map *map);
void		move_forward(t_cub3d *cub3d);
void		move_left(t_cub3d *cub3d);
void		move_backward(t_cub3d *cub3d);
void		move_right(t_cub3d *cub3d);
void		rotate_right(t_cub3d *cub3d);
void		rotate_left(t_cub3d *cub3d);
void		cast_ray(t_cub3d *cub3d);
void		init_img(void *mlx, t_canvas *canvas);
void		init_texture(t_cub3d *cub3d);
void		draw_line(t_cub3d *cub3d, int x);
void		cast_ray(t_cub3d *cub3d);
void		put_pixel(t_canvas *canvas, int x, int y, unsigned int color);
int			key_handler(int keycode, t_cub3d *cub3d);
int			expose(void *ptr);
t_canvas	*new_canvas(void);
t_cub3d		*init_cub3d(t_map *map);
t_user		*new_user(t_map *map);

#endif
