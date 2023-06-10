/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:23:37 by seojin            #+#    #+#             */
/*   Updated: 2022/10/24 16:23:37 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_pair(char *str)
{
	int	cnt_brace;

	cnt_brace = 0;
	while (*str)
	{
		if (*str == Q_SINGLE)
			str = ft_strchr(++str, Q_SINGLE);
		else if (*str == Q_DOUBLE)
			str = ft_strchr(++str, Q_DOUBLE);
		else if (*str == '(')
			cnt_brace++;
		else if (*str == ')')
			cnt_brace--;
		if (!str || cnt_brace < 0)
			return (0);
		str++;
	}
	if (cnt_brace)
		return (0);
	return (1);
}

t_token	*parse_line(char *str)
{
	t_symbol	*symbol_lst;

	if (!check_pair(str))
	{
		free(str);
		error_msg("incomplete command");
		return (0);
	}
	symbol_lst = expand_env(make_symbol_lst(preprocess_line(str)));
	if (!symbol_lst)
		return (0);
	symbolizing(symbol_lst);
	if (validate(symbol_lst))
	{
		free_symbols(symbol_lst);
		return (0);
	}
	expand_filename(symbol_lst);
	return (make_parse_tree(symbol_lst));
}
