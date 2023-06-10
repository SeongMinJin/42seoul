/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:32:52 by seojin            #+#    #+#             */
/*   Updated: 2022/07/24 20:44:50 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_lst
{
	char			*backup;
	int				fd;
	struct s_lst	*next;
}	t_lst;

t_lst	*ft_init(int fd, t_lst **lst);

void	ft_free_lst(t_lst **lst, int fd);
void	ft_bzero(char *buf);

char	*ft_join(t_lst *tmp, char *line, char *src, int size);
char	*get_line(t_lst *tmp, char *buf, int fd, ssize_t *size);
char	*get_next_line(int fd);

int		ft_update_backup(t_lst *tmp, char *src, int i, int size);
int		ft_l_b(char *str, int flag);

#endif
