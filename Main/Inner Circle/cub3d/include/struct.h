/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:55:46 by seojin            #+#    #+#             */
/*   Updated: 2022/11/14 17:29:21 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_map
{
	char	*n_texture;
	char	*s_texture;
	char	*w_texture;
	char	*e_texture;
	int		ceilling_color;
	int		floor_color;
	int		**map;
	int		width;
	int		height;
	int		spawn_x;
	int		spawn_y;
	int		spawn_orientation;
	int		block_size;
}	t_map;

typedef struct s_user
{
	double	curr_x;
	double	curr_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_user;

typedef struct s_canvas
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_canvas;

typedef struct s_texture
{
	void			*img;
	char			*addr;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	unsigned int	**arr;
}	t_texture;

typedef struct s_cub3d
{
	void				*mlx;
	void				*mlx_win;
	struct s_map		*map;
	struct s_user		*user;
	struct s_canvas		*canvas;
	struct s_texture	*n_texture;
	struct s_texture	*s_texture;
	struct s_texture	*w_texture;
	struct s_texture	*e_texture;
	int					map_x;
	int					map_y;
	int					step_x;
	int					step_y;
	int					side;
	double				raydir_x;
	double				raydir_y;
	double				side_x;
	double				side_y;
	double				d_x;
	double				d_y;
	double				perp_d;
}	t_cub3d;

typedef struct s_dummy
{
	int			height;
	int			start;
	int			end;
	int			tex_x;
	double		step;
	double		tex_y_pos;
	t_texture	*texture;
}	t_dummy;

typedef struct s_mapcontents
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	int			filed[6];
}	t_mapcontents;

#endif
