/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:27:30 by seojin            #+#    #+#             */
/*   Updated: 2022/08/31 20:57:51 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_free_instruction(char **instruction)
{
	int	i;

	i = 0;
	while (*(instruction + i))
	{
		free(*(instruction + i));
		i++;
	}
	free(instruction);
}

static void	ft_end(t_stack **a, t_stack **b, \
char **instruction, char *str)
{
	if (ft_ascending_check(*a) && !*b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_lst(a);
	ft_free_lst(b);
	if (instruction)
		ft_free_instruction(instruction);
	if (str)
		free(str);
}

void	ft_verify(t_stack **a, t_stack **b)
{
	char	buf[2];
	char	*str;
	char	**instruction;
	int		i;

	str = 0;
	while (read(0, buf, 1))
	{
		str = ft_glue(str, buf[0]);
		if (!str)
			return ;
	}
	if (str)
	{
		instruction = ft_split(str, '\n');
		i = 0;
		while (*(instruction + i))
			ft_verify2(a, b, *(instruction + i++));
		ft_end(a, b, instruction, str);
	}
	else
		ft_end(a, b, 0, 0);
}
