/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:10:31 by seojin            #+#    #+#             */
/*   Updated: 2022/10/01 17:46:36 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	ft_atoi(char *s)
{
	int	num;

	if (*s == '+')
		s++;
	if (*s < '0' || *s > '9')
		return (ARG_ERR);
	num = 0;
	while ('0' <= *s && *s <= '9')
		num = num * 10 + *s++ - 48;
	if (*s)
		return (ARG_ERR);
	return (num);
}
