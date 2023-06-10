/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:07:54 by seojin            #+#    #+#             */
/*   Updated: 2022/04/21 15:47:14 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	emmigration(char *str, char *to_find, int find_len)
{
	int	index;
	int	check_value;

	index = 0;
	check_value = 0;
	while (to_find[index] != 0 && str[index] != 0)
	{
		if (to_find[index] == str[index])
			check_value++;
		index++;
	}
	if (check_value == find_len)
		return (1);
	else
		return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	str_index;
	int	check_value;
	int	find_len;

	find_len = 0;
	while (to_find[find_len] != 0)
		find_len++;
	str_index = 0;
	check_value = 0;
	if (to_find[0] == 0)
		return (str);
	while (str[str_index] != 0)
	{
		if (emmigration(&str[str_index], to_find, find_len))
		{
			return (&str[str_index]);
			break ;
		}
		str_index++;
	}
	return (0);
}
