/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:40:14 by seojin            #+#    #+#             */
/*   Updated: 2022/10/01 17:41:34 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

typedef struct s_coordinate
{
	int					z;
	double				x;
	double				y;
	struct s_coordinate	*next;
}	t_coordinate;

typedef struct s_map
{
	char			*temp_map;
	char			**str_map;
	int				**int_map;
	int				width;
	int				height;
	int				degree;
	int				benchmark_x;
	int				benchmark_y;
	unsigned int	scale;
	t_coordinate	**coordinate;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map;
}				t_data;

#endif
