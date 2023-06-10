/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:24:19 by seojin            #+#    #+#             */
/*   Updated: 2022/10/24 16:24:19 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	error_msg_exit(char *arg, int code)
{
	if (arg)
	{
		printf("%s: exit: %s: numeric argument required\n", SHELL, arg);
		exit(code);
	}
	else
		printf("%s: exit: too many arguments\n", SHELL);
}

static void	exit_with_exit(int code, int pipe_cnt, char *arg, int error)
{
	if (!pipe_cnt)
		printf("exit\n");
	if (error)
	{
		error_msg_exit(arg, code);
		if (!arg)
		{
			set_exit_code(1);
			return ;
		}
	}
	exit(code);
}

void	ft_exit(char **arg, int pipe_cnt)
{
	int	i;

	(void)pipe_cnt;
	if (arg[1])
	{
		i = 0;
		while (arg[1][i] && ft_isdigit(arg[1][i]))
			++i;
		if (i < (int)ft_strlen(arg[1]))
			exit_with_exit(255, pipe_cnt, arg[1], 1);
		if (arg[2])
			exit_with_exit(1, pipe_cnt, NULL, 1);
		else
			exit_with_exit(ft_atoi(arg[1]), pipe_cnt, NULL, 0);
	}
	else
		exit_with_exit(0, pipe_cnt, NULL, 0);
}
