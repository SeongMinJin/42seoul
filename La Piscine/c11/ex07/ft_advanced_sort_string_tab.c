/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advancde_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:48:02 by seojin            #+#    #+#             */
/*   Updated: 2022/05/03 19:55:53 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap2(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	len;
	int	i;
	int	j;

	len = 0;
	while (tab[len])
		len++;
	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len -1)
		{
			if ((*cmp)(tab[j], tab[j + 1]) > 0)
				ft_swap2(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}
