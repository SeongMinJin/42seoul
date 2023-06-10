/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 22:14:48 by seojin            #+#    #+#             */
/*   Updated: 2022/05/02 01:45:52 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(int size, char **str, char *sep)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	i = 0;
	if (size == 0)
		return (0);
	while (i < size)
	{
		j = 0;
		while (str[i][j])
		{
			j++;
			len++;
		}
		i++;
	}
	i = 0;
	while (sep[i])
		i++;
	return (len + (i * (size - 1)));
}

void	ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
}

char	*ft_strjoin(int size, char **str, char *sep)
{
	char	*sstr;
	int		i;
	int		len;

	len = ft_strlen(size, str, sep);
	sstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	sstr[0] = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(sstr, str[i]);
		if (i == size - 1)
			break ;
		ft_strcat(sstr, sep);
		i++;
	}
	return (sstr);
}
