/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:32:16 by seojin            #+#    #+#             */
/*   Updated: 2022/07/24 20:47:06 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_free_line(char *line)
{
	if (line)
		free(line);
	return (0);
}

char	*ft_join(t_lst *tmp, char *line, char *src, int size)
{
	char	*str;
	int		l_len;
	int		i;

	i = 0;
	l_len = ft_l_b(line, 1);
	str = (char *)malloc((l_len + size + 1) * sizeof(char));
	if (!str)
		ft_free_line(line);
	*(str + (l_len + size)) = 0;
	while (line && i < l_len)
	{
		*(str + i) = *(line + i);
		i++;
	}
	while (size--)
		*(str + i++) = *src++;
	if (line)
		free(line);
	if (!ft_update_backup(tmp, src, 0, 0))
		return (0);
	return (str);
}

char	*get_line(t_lst *tmp, char *buf, int fd, ssize_t *size)
{
	char	*line;

	line = 0;
	if (ft_l_b(tmp->backup, 0) != -1)
		return (ft_join(tmp, line, tmp->backup, ft_l_b(tmp->backup, 0)));
	*size = read(fd, buf, BUFFER_SIZE);
	if (*size < 0)
		return (0);
	while (*size >= 0)
	{
		if (*size == 0 && tmp->backup == 0)
			break ;
		if (tmp->backup)
			line = ft_join(tmp, line, tmp->backup, ft_l_b(tmp->backup, 1));
		if (ft_l_b(buf, 0) != -1)
		{
			line = ft_join(tmp, line, buf, ft_l_b(buf, 0));
			break ;
		}
		if (*buf)
			line = ft_join(tmp, line, buf, ft_l_b(buf, 1));
		ft_bzero(buf);
		*size = read(fd, buf, BUFFER_SIZE);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_lst	*lst;
	t_lst			*tmp;
	char			*line;
	char			buf[BUFFER_SIZE + 1];
	ssize_t			size;

	tmp = ft_init(fd, &lst);
	if (!tmp)
		return (0);
	ft_bzero(buf);
	line = get_line(tmp, buf, fd, &size);
	if (size < 0 || (size == 0 && tmp->backup == 0))
		ft_free_lst(&lst, fd);
	return (line);
}
