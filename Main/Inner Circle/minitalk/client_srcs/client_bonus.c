/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:19:59 by seojin            #+#    #+#             */
/*   Updated: 2022/08/12 10:45:05 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

t_info	g_status;

static void	ft_finish(void)
{
	int	i;

	i = 0;
	while (g_status.bit != 8 || g_status.c != CONFIRM)
	{
		while (i < 8)
		{
			kill(g_status.pid, SIGUSR2);
			usleep(g_status.timer);
			i++;
		}
		g_status.byte++;
		if (g_status.byte > 2148473646)
			ft_exit(INVALID_PID);
	}
}

static pid_t	ft_atopid(const char *s)
{
	pid_t	pid;

	pid = 0;
	if (*s == '-')
		ft_exit(INVALID_PID);
	else if (*s == '+')
		s++;
	while (*s)
	{
		if ('0' <= *s && *s <= '9')
			pid = pid * 10 + *s - 48;
		else
			ft_exit(INVALID_PID);
		s++;
	}
	return (pid);
}

void	signal_handler_1(int signum)
{
	(void) signum;
	if (g_status.bit != 0)
		g_status.c = g_status.c << 1;
	g_status.bit += 1;
	g_status.byte = 0;
	if (g_status.bit == 8 && g_status.c == CONFIRM)
		write(1, "SUCCESS!\n", 9);
	else if (g_status.bit == 8 && g_status.c == MALLOC_ERROR)
		ft_exit(MALLOC_ERROR);
}

void	signal_handler_2(int signum)
{
	(void) signum;
	if (g_status.bit != 0)
		g_status.c = g_status.c << 1;
	g_status.c += 1;
	g_status.bit += 1;
	g_status.byte = 0;
	if (g_status.bit == 8 && g_status.c == CONFIRM)
		write(1, "SUCCESS!\n", 9);
	else if (g_status.bit == 8 && g_status.c == MALLOC_ERROR)
		ft_exit(MALLOC_ERROR);
}

int	main(int ac, char **av)
{
	unsigned char	curr;
	int				i;

	if (ac != 3)
		ft_exit(ARGC_FAIL);
	ft_init_status(&g_status, ft_atopid(av[1]), av[2]);
	signal(SIGUSR1, signal_handler_1);
	signal(SIGUSR2, signal_handler_2);
	write(1, "WAITING...\n", 11);
	while (*(g_status.str))
	{
		curr = *(g_status.str);
		i = 0;
		while (i < 8)
		{
			ft_send_signal(curr, g_status.pid);
			ft_next_step(&g_status, &curr, &i);
		}
		(g_status.str)++;
	}
	ft_finish();
	return (0);
}
