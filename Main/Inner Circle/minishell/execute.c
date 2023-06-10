/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:22:17 by seojin            #+#    #+#             */
/*   Updated: 2022/10/24 16:22:17 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_exit_code(void)
{
	if (!ft_strcmp(g_info->exit_code, "0"))
		return (0);
	else
		return (1);
}

void	execute_tree(t_token *tree)
{
	if (!tree)
		return ;
	if (tree->left)
		execute_tree(tree->left);
	if (tree->symbol->type == T_AND_IF || tree->symbol->type == T_OR_IF)
	{
		if ((tree->symbol->type == T_AND_IF && !check_exit_code())
			|| (tree->symbol->type == T_OR_IF && check_exit_code()))
			execute_tree(tree->right);
	}
	else
		execute_pipe_line(tree->symbol);
}
