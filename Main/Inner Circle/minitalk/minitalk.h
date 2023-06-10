/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:40:58 by seojin            #+#    #+#             */
/*   Updated: 2022/08/11 21:46:23 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_info
{
	unsigned char	*str;
	unsigned char	c;
	int				stop;
	size_t			bit;
	size_t			byte;
	size_t			timer;
	pid_t			pid;
	pid_t			stranger;
}	t_info;

# define EMPTY 0
# define ARGC_FAIL 0
# define INVALID_PID 1
# define MALLOC_ERROR 15
# define FINISH 255
# define CONFIRM 240

void	ft_accumulate_bit(t_info *info, int bit);
void	ft_clean_server(t_info *info);
void	ft_init_info(t_info *info);
void	ft_memmove(unsigned char *dst, unsigned char *src, size_t size);
void	ft_ready_to_get_next_letter(t_info *info);
void	ft_null_guard(t_info *info);
void	ft_print(t_info *info);
void	ft_putpid(pid_t pid);

void	ft_next_step(t_info *status, unsigned char *curr, int *i);
void	ft_send_signal(unsigned char curr, pid_t pid);
void	ft_init_status(t_info *status, pid_t pid, char *str);
void	ft_exit(int flag);
void	ft_clean_client(t_info *info);

#endif
