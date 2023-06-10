/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:43:19 by seojin            #+#    #+#             */
/*   Updated: 2022/07/15 07:40:32 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_counter(char const *s, char c)
{
	size_t	cnt;

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

static void	*ft_free(char **arr, size_t idx)
{
	size_t	i;

	i = 0;
	while (i < idx)
		free(*(arr + i++));
	free(arr);
	return (NULL);
}

static char	*ft_suction(char *str, char c)
{
	char	*s;
	size_t	size;

	size = 0;
	while (*(str + size) && *(str + size) != c)
		size++;
	s = (char *)malloc((size + 1) * sizeof(char));
	if (!s)
		return (NULL);
	*(s + size) = 0;
	while (*str && *str != c)
		*s++ = *str++;
	return (s - size);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	word_num;
	size_t	idx;

	word_num = ft_word_counter(s, c);
	arr = (char **)malloc((word_num + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	*(arr + word_num) = 0;
	idx = 0;
	while (*s && word_num != 0)
	{
		while (*s && *s == c)
			s++;
		*(arr + idx) = ft_suction((char *)s, c);
		if (!(arr + idx))
			return (ft_free(arr, idx + 1));
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
		idx++;
	}
	return (arr);
}
