/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:52:59 by seojin            #+#    #+#             */
/*   Updated: 2022/08/21 15:22:50 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit(int err_code)
{
	if (err_code == OPEN_ERROR)
		perror("open");
	else if (err_code == MALLOC_ERROR)
		perror("malloc");
	else if (err_code == MLX_INIT_ERROR)
		perror("mlx");
	exit(1);
}
