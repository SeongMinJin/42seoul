/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 02:25:16 by seojin            #+#    #+#             */
/*   Updated: 2022/04/28 14:20:08 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	action(int nb, long long sqrt)
{
	if (sqrt * sqrt > nb)
		return (0);
	else if (sqrt * sqrt == nb)
		return (sqrt);
	else
		return (action(nb, sqrt + 1));
}

int	ft_sqrt(int nb)
{
	return (action(nb, 1));
}
