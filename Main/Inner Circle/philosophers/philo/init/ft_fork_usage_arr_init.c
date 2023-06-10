/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_usage_arr_init.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:09:51 by seojin            #+#    #+#             */
/*   Updated: 2022/10/03 11:13:21 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_fork_usage_arr_init(t_status *status, int num)
{
	int	i;
	int	*fork_usage_arr;

	fork_usage_arr = (int *)malloc(num * sizeof(int));
	if (!fork_usage_arr)
		status->fork_usage_arr = NULL;
	else
	{
		i = 0;
		while (i < num)
			fork_usage_arr[i++] = 0;
		status->fork_usage_arr = fork_usage_arr;
	}
}
