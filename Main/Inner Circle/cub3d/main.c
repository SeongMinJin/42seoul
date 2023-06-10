/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:56:30 by seojin            #+#    #+#             */
/*   Updated: 2022/11/14 12:34:55 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		ft_error(AC_ERR);
	map = parse_map(av[1]);
	execute(map);
	exit(0);
}
