/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:01:04 by seojin            #+#    #+#             */
/*   Updated: 2022/04/25 13:13:38 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int				index;
	unsigned char	s1_val;
	unsigned char	s2_val;

	index = 0;
	if (s1[0] == 0 && s2[0] == 0)
		return (0);
	while (s1[index] == s2[index])
	{
		if (s1[index] == 0 && s2[index] == 0)
			break ;
		index++;
	}
	s1_val = s1[index];
	s2_val = s2[index];
	return (s1_val - s2_val);
}
