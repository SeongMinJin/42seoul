/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 09:51:46 by seojin            #+#    #+#             */
/*   Updated: 2022/07/14 14:39:32 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	size_t	len = n <= 0 ? 1 : 0;

	while (n)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		temp_n = n;
	int		len = ft_nbrlen(n);
	char	*nbr = (char *)malloc((len + 1) * sizeof(char));

	if (nbr == NULL)
		return NULL;
	nbr = nbr + len;
	*nbr = '\0';
	while (temp_n)
	{
		if (n < 0)
			*--nbr = -(temp_n % 10) + 48;
		else
			*--nbr = temp_n % 10 + 48;
		temp_n /= 10;
	}
	if (n < 0)
		*--nbr = '-';
	else if (n == 0)
		*--nbr = '0';
	return (nbr);
}
