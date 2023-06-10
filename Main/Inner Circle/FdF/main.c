/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:49:10 by seojin            #+#    #+#             */
/*   Updated: 2022/10/03 16:00:08 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	(void) ac;
	ft_draw(ft_create_coordinate(ft_read_map(av[1])));
	ft_read_map(av[1]);
	return (0);
}
