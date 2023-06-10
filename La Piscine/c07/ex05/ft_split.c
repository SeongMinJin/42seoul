/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 02:09:02 by seojin            #+#    #+#             */
/*   Updated: 2022/05/01 03:46:03 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_separator_check(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_num_of_word(char *str, char *charset)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (ft_separator_check(str[i], charset) && str[i] != 0)
			i++;
		if (str[i] != 0)
			cnt++;
		while (!ft_separator_check(str[i], charset) && str[i] != 0)
			i++;
	}
	return (cnt);
}

char	*ft_suction_word(char *str, char *charset)
{
	char	*word;
	int		word_len;
	int		idx;

	word_len = 0;
	while (!ft_separator_check(str[word_len], charset) && str[word_len] != 0)
		word_len++;
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	word[word_len] = 0;
	idx = 0;
	while (idx < word_len)
	{
		word[idx] = str[idx];
		idx++;
	}
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**strings;
	int		num_of_word;
	int		p_idx;
	int		pp_idx;

	num_of_word = ft_num_of_word(str, charset);
	strings = (char **)malloc(sizeof(char *) * (num_of_word + 1));
	if (!strings)
		return (0);
	strings[num_of_word] = 0;
	p_idx = 0;
	pp_idx = 0;
	while (str[p_idx])
	{
		while (ft_separator_check(str[p_idx], charset) && str[p_idx] != 0)
			p_idx++;
		if (str[p_idx] != 0)
		{
			strings[pp_idx] = ft_suction_word(&str[p_idx], charset);
			pp_idx++;
		}
		while (!ft_separator_check(str[p_idx], charset) && str[p_idx] != 0)
			p_idx++;
	}
	return (strings);
}
