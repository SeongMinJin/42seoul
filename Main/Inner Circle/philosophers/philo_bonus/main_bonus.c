/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:48:35 by seojin            #+#    #+#             */
/*   Updated: 2022/09/29 12:02:50 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_status	*status;

	if (ac < 5 || ac > 6)
		return (0);
	status = ft_init(++av);
	ft_start(status);
	exit(0);
}
