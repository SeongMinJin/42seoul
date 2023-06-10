/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:54:24 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:48 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_atoi(char *str)
{
	int	num;

	while (*str == ' ')
		str++;
	if (*str == '+')
		str++;
	if (*str < '0' || *str > '9')
		ft_error(INVALID_RGB);
	num = 0;
	while ('0' <= *str && *str <= '9')
		num = num * 10 + *str++ - 48;
	while (*str == ' ')
		str++;
	if (*str || num > 255 || num < 0)
		ft_error(INVALID_RGB);
	return (num);
}
