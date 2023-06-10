/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:56:13 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 14:56:39 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*read_file(char	*file_name)
{
	char	buf[1];
	char	*file_data;
	int		fd;
	int		rbyte;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_error(NO_SUCH_FILE);
	rbyte = 0;
	while (read(fd, buf, 1))
		++rbyte;
	close(fd);
	file_data = (char *)malloc((rbyte + 1) * sizeof(char));
	if (!file_data)
		exit(MALLOC_ERR);
	file_data[rbyte] = '\0';
	fd = open(file_name, O_RDONLY);
	read(fd, file_data, rbyte);
	close(fd);
	return (file_data);
}
