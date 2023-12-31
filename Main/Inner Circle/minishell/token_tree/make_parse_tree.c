/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_parse_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:21:50 by seojin            #+#    #+#             */
/*   Updated: 2022/10/24 16:21:55 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*make_token(t_symbol *symbol)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		exit(-1);
	token->symbol = symbol;
	token->left = NULL;
	token->right = NULL;
	return (token);
}

t_token	*make_parse_tree(t_symbol *symbol)
{
	t_token			*tree_root;

	tree_root = and_or(symbol);
	return (tree_root);
}
