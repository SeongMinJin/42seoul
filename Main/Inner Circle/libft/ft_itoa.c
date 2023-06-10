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
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		temp_n;
	int		len;

	temp_n = n;
	len = ft_nbrlen(n);
	nbr = (char *)malloc((len + 1) * sizeof(char));
	if (nbr == NULL)
		return (NULL);
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
