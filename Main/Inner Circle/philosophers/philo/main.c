/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:57:34 by seojin            #+#    #+#             */
/*   Updated: 2023/02/27 14:41:26 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_status	*status;

	if (ac < 5 || ac > 6)
		return (0);
	status = ft_init(++av);
	if (!status)
		return (0);
	ft_start(status);
	// usleep(2000000);
	ft_clean(status);
	return (0);
}
