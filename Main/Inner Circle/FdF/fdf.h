/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:08:11 by seojin            #+#    #+#             */
/*   Updated: 2022/10/03 12:57:34 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./mlx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# include "fdf_struct.h"
# include "fdf_macro.h"

void	ft_exit(int err_code);
void	ft_draw(t_map map);
void	ft_mlx_pixel_put(t_img *data, int x, int y, int color);
void	ft_free_int_map(int **arr, int idx);
void	ft_free_str_map(char **str);
void	ft_draw_square(t_img *img, t_map map);
void	ft_connect_dots(t_img img, t_map map);
void	ft_zoom(t_data *data, int keycode);
void	ft_move(t_data *data, int keycode);

void	ft_free_lst(t_coordinate *head);
void	ft_free_coordinate(t_coordinate **coordinate, int idx);
void	ft_free_int_map(int **arr, int idx);
void	ft_free_str_map(char **str);
void	ft_escape(t_data *data);

char	**ft_split(char *s, char c);

int		ft_get_width(char *map);
int		ft_get_height(char **map);
int		ft_atoi(char *s);
int		*ft_set_color(t_map *map);

double	ft_deg_to_rad(double deg);

t_img	ft_img_init(void *mlx);
t_map	ft_read_map(char *map_file);
t_map	ft_create_coordinate(t_map map);

#endif
