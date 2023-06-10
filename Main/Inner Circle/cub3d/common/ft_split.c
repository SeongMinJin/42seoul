/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:54:42 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:47 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_word_counter(char *s, char c);
static char	*ft_suction(char *str, char c);

char	**ft_split(char *s, char c)
{
	char	**arr;
	int		word_num;
	int		idx;

	word_num = ft_word_counter(s, c);
	arr = (char **)malloc((word_num + 1) * sizeof(char *));
	if (!arr)
		exit(MALLOC_ERR);
	arr[word_num] = NULL;
	idx = 0;
	while (*s && word_num != 0)
	{
		while (*s && *s == c)
			s++;
		arr[idx] = ft_suction(s, c);
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
		idx++;
	}
	return (arr);
}

static int	ft_word_counter(char *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{	
		while (*s && *s == c)
			s++;
		if (!*s)
			return (cnt);
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
		cnt++;
	}
	return (cnt);
}

static char	*ft_suction(char *str, char c)
{
	char	*s;
	int		size;

	size = 0;
	while (*(str + size) && *(str + size) != c)
		size++;
	s = (char *)malloc((size + 1) * sizeof(char));
	if (!s)
		exit(MALLOC_ERR);
	s[size] = 0;
	while (*str && *str != c)
		*s++ = *str++;
	return (s - size);
}
