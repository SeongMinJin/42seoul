/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:47:56 by seojin            #+#    #+#             */
/*   Updated: 2022/08/12 10:45:48 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

t_info	g_client_info;

void	signal_handler_1(int signum, siginfo_t *info, void *status)
{
	(void) signum;
	(void) status;
	if (g_client_info.pid == EMPTY)
		g_client_info.pid = info->si_pid;
	ft_accumulate_bit(&g_client_info, 0);
	if (g_client_info.bit == 8 && g_client_info.c != FINISH)
		ft_ready_to_get_next_letter(&g_client_info);
	else if (g_client_info.bit == 8 && g_client_info.c == FINISH)
	{
		ft_print(&g_client_info);
		ft_init_info(&g_client_info);
	}
}

void	signal_handler_2(int signum, siginfo_t *info, void *status)
{
	(void) signum;
	(void) status;
	if (g_client_info.pid == EMPTY)
		g_client_info.pid = info->si_pid;
	ft_accumulate_bit(&g_client_info, 1);
	if (g_client_info.bit == 8 && g_client_info.c != FINISH)
		ft_ready_to_get_next_letter(&g_client_info);
	else if (g_client_info.bit == 8 && g_client_info.c == FINISH)
	{
		ft_print(&g_client_info);
		ft_init_info(&g_client_info);
	}
}

int	main(void)
{
	struct sigaction	act1;
	struct sigaction	act2;

	act1.sa_flags = SA_SIGINFO;
	act1.sa_sigaction = signal_handler_1;
	act2.sa_flags = SA_SIGINFO;
	act2.sa_sigaction = signal_handler_2;
	ft_putpid(getpid());
	ft_init_info(&g_client_info);
	sigaction(SIGUSR1, &act1, 0);
	sigaction(SIGUSR2, &act2, 0);
	while (1)
		pause();
	return (0);
}
