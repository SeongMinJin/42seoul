/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_wild_card.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:23:46 by seojin            #+#    #+#             */
/*   Updated: 2022/10/24 16:23:46 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	replace_back_wild_card(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] < 0)
				str[i][j] *= -1;
			j++;
		}
		i++;
	}
}

void	replace_wild_card(char *str)
{
	while (*str)
	{
		if (*str == Q_DOUBLE)
		{
			str++;
			while (*str != Q_DOUBLE)
			{
				if (*str == '*')
					*str *= -1;
				str++;
			}
		}
		if (*str == Q_SINGLE)
		{
			str++;
			while (*str != Q_SINGLE)
			{
				if (*str == '*')
					*str *= -1;
				str++;
			}
		}
		str++;
	}
}
